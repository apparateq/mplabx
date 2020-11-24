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

// Function prototypes
void setLEDs(uint8_t val);

// Utility functions

void fast_blink() {
  uint8_t i;
  for (i = 0; i < 2; i++) {
    setLEDs(0x0f);
    __delay_ms(50);
    setLEDs(0x00);
    __delay_ms(50);
  }
}

// overload putch() so printf() goes to UART
void putch(char data) {
  while (! PIR1bits.TXIF) {
    continue;
  }
  TXREG = data;
}

// map lower four bits of val to LEDs D7-D4
void setLEDs(uint8_t val) {
  LED_D7_LAT = (val & 1) >> 0;
  LED_D6_LAT = (val & 2) >> 1;
  LED_D5_LAT = (val & 4) >> 2;
  LED_D4_LAT = (val & 8) >> 3;
}

// Applications

uint8_t receiveCommand() {
  uint8_t state = 0;
  uint8_t ch;
  uint8_t port;
  
  while (state != 3) {
    ch = EUSART_Read();
    //printf("\r\nstate: %d [%c] (%d)", state, ch, ch);
    
    switch (state) {
      case 0:
        if (ch == 'A') { // data must start with 'A'
          printf("%c", ch);
          state = 1;
        } else {
          fast_blink();
        }
        break;
        
      case 1:
        port = ch;
        if (port < 48 || port > 51) { // only accept '0', '1', '2', '3'
          fast_blink();
          state = 0;
        } else {
          printf("%c", ch);
          state = 2;
        }
        break;
        
      case 2:
        if (ch == 10 || ch == 13) { // terminate with '\n' or '\r'
          printf("(cr)\r\n");
          state = 3;
        } else {
          fast_blink();
          state = 0;
        }
        break;
    }
  }

  return (port - 48); // 0, 1, 2, 3
}

//#define printf(...)

void UARTRxLoop() {
  while (1) {
    // Go to sleep
    printf("sleeping\r\n");
    BAUD1CONbits.WUE = 1;
    SLEEP();

    // Wake up and get some data
    while (BAUD1CONbits.WUE == 1) {}
    EUSART_Read(); // discard
    __delay_ms(50);
    printf("\r\nenter command:\r\n");


    uint8_t command = receiveCommand();
    printf("Command: %d\r\n", command);
    // Enable relevant port
    uint8_t val = (uint8_t)(1 << command);
    setLEDs(val);
  }
}

// Main program loop
void main(void) {
  // initialize the device
  SYSTEM_Initialize();

  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  printf("Welcome!\r\n");
 
  UARTRxLoop();
}
