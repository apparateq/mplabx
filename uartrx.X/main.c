// Copyright (C) 2020 Apparateq
//===----------------------------------------------------------------------===//
///
/// \file
///
/// \brief
///
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include "mcc_generated_files/mcc.h"
#include "source/aptq_common.h"

//#define DISABLE_PRINTF

#ifdef DISABLE_PRINTF
    #define printf(fmt, ...) (0)
#endif

enum Command {NONE = 0, PORT, MULTIPORT};

// Utility functions

// LED functions
#define BLNK_BAD_CHECKSUM 0xA
#define BLNK_BAD_COMMAND  0xC
#define BLNK_BAD_VALUE    0xF
#define BLINK_DELAY 50

// Turn on leds corresponding to the bitmask (lower four bits)
void setLEDs(uint8_t mask) {
  PORTA_LED_LAT = (mask & 8) >> 3;
  PORTB_LED_LAT = (mask & 4) >> 2;
  PORTC_LED_LAT = (mask & 2) >> 1;
  PORTD_LED_LAT = (mask & 1) >> 0;
}

// Do a sweep to indicate a good command
void good_blink() {
    setLEDs(8);
    __delay_ms(BLINK_DELAY);
    setLEDs(4);
    __delay_ms(BLINK_DELAY);
    setLEDs(2);
    __delay_ms(BLINK_DELAY);
    setLEDs(1);
    __delay_ms(BLINK_DELAY);
    setLEDs(0);
}

// Fast double blink for errors
void fast_blink(uint8_t val) {
  uint8_t i;
  for (i = 0; i < 2; i++) {
    setLEDs(val);
    __delay_ms(BLINK_DELAY);
    setLEDs(0x00);
    __delay_ms(BLINK_DELAY);
  }
}


// overload putch() so printf() goes to UART
void putch(char data) {
  while (! PIR1bits.TXIF) {
    continue;
  }
  TXREG = data;
}



/// Parser

// Port command takes values '0' - '4'
// 0: no active ports
// 1: port D
// 2: port C
// 3: port B
// 4: port A
void cmd_port(uint8_t value) {
  uint8_t mask;
  if (value == 0) {
    mask = 0;
  } else {
    mask = (uint8_t)(1 << (4 - value));
  }
  setLEDs(mask);
}

// Multiport command takes ascii values '0' - '?' (16 values bitmask)
void cmd_multiport(uint8_t mask) {
  setLEDs(mask);
}


void receiveCommand() {
  uint8_t state = 0;
  enum Command cmd = NONE;
  uint8_t done = 0;
  uint8_t ch;
  uint8_t cmdbuf[6];
  uint8_t expect; // expected checksum

  while (!done) {
    ch = EUSART_Read();
    cmdbuf[state] = ch;
    //printf("\r\nstate: %d [%c] (%d)", state, ch, ch);

    switch (state) {
      case 0: // Search for start of command
        if (ch == 'A') { // data must start with 'A'
          printf("%c", ch);
          state = 1;
        } else {
          fast_blink(BLNK_BAD_VALUE);
        }
        break;

      case 1: // Command is either 'P' or 'M
        if (ch == 'P') { // Port (P) command accepts values 0, 1, 2, 3
          printf("%c", ch);
          cmd = PORT;
          state = 2;
        } else if (ch == 'M') { // Multiport accepts 0, 1, 2, ... 15)
          printf("%c", ch);
          cmd = MULTIPORT;
          state = 2;
        } else {
          state = 0;
          fast_blink(BLNK_BAD_COMMAND);
        }
        break;

      case 2:
        if ((cmd == PORT) && ((ch < '0') || (ch > '4'))) {
          fast_blink(BLNK_BAD_VALUE);
          state = 0;
        } else if ((cmd == MULTIPORT) && ((ch < '0') || (ch > '?'))) {
          fast_blink(BLNK_BAD_VALUE);
          state = 0;
        } else {
          printf("%c", ch);
          state = 3;
        }
        break;

      case 3:
        expect = cmdbuf[0] ^ cmdbuf[1] ^ cmdbuf[2];
        if (cmdbuf[3] != expect) { // xor cksum must be 0
          printf("Expected %d, got %d\r\n", expect, cmdbuf[3]);
          fast_blink(BLNK_BAD_CHECKSUM);
          state = 0;
        } else {
          printf("(%d)", cmdbuf[3]);
          state = 4;
        }
        break;

      case 4:
        if (ch == 10 || ch == 13) { // terminate with '\n' or '\r'
          printf("(cr)\r\n");
          done = 1;
        } else {
          fast_blink(BLNK_BAD_VALUE);
          state = 0;
        }
        break;
    }
  }
  good_blink();

  if (cmd == PORT) {
    cmd_port(cmdbuf[2] - '0');
  } else if (cmd == MULTIPORT) {
    cmd_multiport(cmdbuf[2] - '0');
  }
}

//
void UARTRxLoop() {
  while (1) {
    // Go to sleep
    printf("(sleep)\r\n");
    BAUD1CONbits.WUE = 1;
    SLEEP();

    // Wake up and get some data
    while (BAUD1CONbits.WUE == 1) {}
    EUSART_Read(); // discard
    __delay_ms(50);
    printf("\r\nenter command:\r\n");

    receiveCommand();
  }
}

// Main program loop
void main(void) {
  // initialize the device
  SYSTEM_Initialize();

  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  printf("\e[1;1H\e[2J");
  printf("Apparateq\r\n\r\n");
  
  while (1) {
    COM_GRN_LED_LAT = 1;
    COM_RED_LED_LAT = 1;
    TEST_LED_LAT = 1;
    PWR_RED_LED_LAT = 1;
    setLEDs(0);
    __delay_ms(1000);
    
    COM_GRN_LED_LAT = 0;
    COM_RED_LED_LAT = 0;
    TEST_LED_LAT = 0;
    PWR_RED_LED_LAT = 0;
    setLEDs(0xff);
    __delay_ms(1000);
  }

  UARTRxLoop();
}
