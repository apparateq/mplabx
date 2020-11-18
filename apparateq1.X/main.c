// Copyright (C) 2020 Apparateq
//===----------------------------------------------------------------------===//
///
/// \file
///
/// \brief Main Demo Program
///
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include "mcc_generated_files/mcc.h"
#include "source/aptq_common.h"
#include "source/aptq_pwm.h"

// Local function prototypes


// Global state variables
bool app_change = false;
bool app_state = NOT_RUNNING;
bool btnState = NOT_PRESSED;
uint8_t program = 0;


// Utility functions

// Toggle state of button S1 - when button is released we signal next app
void checkButtonS1(void){
    if(btnState == NOT_PRESSED){
        if(BUTTON_S1_PORT == LOW){
            __delay_ms(100);
            btnState = PRESSED;
        }
    }else if(BUTTON_S1_PORT == HIGH){
            btnState = NOT_PRESSED;
            app_change = 1;
    }
}

// increment app number and wrap around
void nextApp(void) {
    app_change = false;
    program++;

    if (program > 3) {
        program = 0;
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

// Read potentiometer fra ADC, display four upper bits in LEDs
void ADC(void) {
  if (app_state == NOT_RUNNING) {
    app_state = RUNNING;
  }

  if (app_state == RUNNING) {
    uint8_t adcResult = 0;
    // Get the top 4 MSBs and display it on the LEDs
    adcResult = ADC_GetConversion(POT_CHANNEL) >> 12;
    setLEDs(adcResult);
  }

  if (app_change) {
    app_state = NOT_RUNNING;
  }
}

// Show lower four bits of 8 bit counter on the LEDs
void blink_leds() {
  static uint8_t val = 0;
  setLEDs(val);
  __delay_ms(100);
  val++;
}

// Read char from asynchronous UART, show lower four bits
void asynch_read() {
  uint8_t rx = EUSART_Read();
  if (rx != 0) {
    setLEDs(rx);
  }
}


// Moving demo out of main loop
void demo() {
  while (1){
   checkButtonS1();
   switch (program) {
     case 0:
       ADC();
       break;
     case 1:
       PWM();
       break;
     case 2:
       blink_leds();
       break;
     case 3:
       asynch_read();
       break;
     default:
       break;
   }
   if (app_change) {
     nextApp();
     setLEDs(0);
   }
  }
}


uint16_t receiveCommand() {
  while (BAUDCONbits.WUE);

  uint8_t discard = EUSART_Read();
  uint8_t b1 = EUSART_Read();

  printf("Got: 0x02x and 0x%02x\n", discard, b1);
  return b1;
}


void UARTRxLoop() {
  while (1) {
    // Go to sleep
    BAUD1CONbits.WUE = 1;
    SLEEP();
    // Wake up and get some data
    uint16_t command = receiveCommand();
    // Enable relevant port
    setLEDs(command & 0xff);
  }
}

// Main program loop
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    printf("Welcome!\n");

    UARTRxLoop();
    // not reached
    demo();


}
