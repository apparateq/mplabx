/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set COM_GRN_LED aliases
#define COM_GRN_LED_TRIS                 TRISAbits.TRISA4
#define COM_GRN_LED_LAT                  LATAbits.LATA4
#define COM_GRN_LED_PORT                 PORTAbits.RA4
#define COM_GRN_LED_WPU                  WPUAbits.WPUA4
#define COM_GRN_LED_OD                   ODCONAbits.ODCA4
#define COM_GRN_LED_ANS                  ANSELAbits.ANSA4
#define COM_GRN_LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define COM_GRN_LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define COM_GRN_LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define COM_GRN_LED_GetValue()           PORTAbits.RA4
#define COM_GRN_LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define COM_GRN_LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define COM_GRN_LED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define COM_GRN_LED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define COM_GRN_LED_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define COM_GRN_LED_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define COM_GRN_LED_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define COM_GRN_LED_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set COM_RED_LED aliases
#define COM_RED_LED_TRIS                 TRISAbits.TRISA5
#define COM_RED_LED_LAT                  LATAbits.LATA5
#define COM_RED_LED_PORT                 PORTAbits.RA5
#define COM_RED_LED_WPU                  WPUAbits.WPUA5
#define COM_RED_LED_OD                   ODCONAbits.ODCA5
#define COM_RED_LED_ANS                  ANSELAbits.ANSA5
#define COM_RED_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define COM_RED_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define COM_RED_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define COM_RED_LED_GetValue()           PORTAbits.RA5
#define COM_RED_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define COM_RED_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define COM_RED_LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define COM_RED_LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define COM_RED_LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define COM_RED_LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define COM_RED_LED_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define COM_RED_LED_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set TEST_LED aliases
#define TEST_LED_TRIS                 TRISBbits.TRISB4
#define TEST_LED_LAT                  LATBbits.LATB4
#define TEST_LED_PORT                 PORTBbits.RB4
#define TEST_LED_WPU                  WPUBbits.WPUB4
#define TEST_LED_OD                   ODCONBbits.ODCB4
#define TEST_LED_ANS                  ANSELBbits.ANSB4
#define TEST_LED_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define TEST_LED_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define TEST_LED_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define TEST_LED_GetValue()           PORTBbits.RB4
#define TEST_LED_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define TEST_LED_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define TEST_LED_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define TEST_LED_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define TEST_LED_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define TEST_LED_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define TEST_LED_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define TEST_LED_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set PORTB_LED aliases
#define PORTB_LED_TRIS                 TRISCbits.TRISC3
#define PORTB_LED_LAT                  LATCbits.LATC3
#define PORTB_LED_PORT                 PORTCbits.RC3
#define PORTB_LED_WPU                  WPUCbits.WPUC3
#define PORTB_LED_OD                   ODCONCbits.ODCC3
#define PORTB_LED_ANS                  ANSELCbits.ANSC3
#define PORTB_LED_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PORTB_LED_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PORTB_LED_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PORTB_LED_GetValue()           PORTCbits.RC3
#define PORTB_LED_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PORTB_LED_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PORTB_LED_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define PORTB_LED_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define PORTB_LED_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define PORTB_LED_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define PORTB_LED_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PORTB_LED_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set PORTA_LED aliases
#define PORTA_LED_TRIS                 TRISCbits.TRISC4
#define PORTA_LED_LAT                  LATCbits.LATC4
#define PORTA_LED_PORT                 PORTCbits.RC4
#define PORTA_LED_WPU                  WPUCbits.WPUC4
#define PORTA_LED_OD                   ODCONCbits.ODCC4
#define PORTA_LED_ANS                  ANSELCbits.ANSC4
#define PORTA_LED_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define PORTA_LED_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define PORTA_LED_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define PORTA_LED_GetValue()           PORTCbits.RC4
#define PORTA_LED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define PORTA_LED_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define PORTA_LED_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define PORTA_LED_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define PORTA_LED_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define PORTA_LED_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define PORTA_LED_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define PORTA_LED_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set PWR_RED_LED aliases
#define PWR_RED_LED_TRIS                 TRISCbits.TRISC5
#define PWR_RED_LED_LAT                  LATCbits.LATC5
#define PWR_RED_LED_PORT                 PORTCbits.RC5
#define PWR_RED_LED_WPU                  WPUCbits.WPUC5
#define PWR_RED_LED_OD                   ODCONCbits.ODCC5
#define PWR_RED_LED_ANS                  ANSELCbits.ANSC5
#define PWR_RED_LED_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PWR_RED_LED_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PWR_RED_LED_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PWR_RED_LED_GetValue()           PORTCbits.RC5
#define PWR_RED_LED_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PWR_RED_LED_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PWR_RED_LED_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define PWR_RED_LED_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define PWR_RED_LED_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define PWR_RED_LED_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define PWR_RED_LED_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define PWR_RED_LED_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set PORTC_LED aliases
#define PORTC_LED_TRIS                 TRISCbits.TRISC6
#define PORTC_LED_LAT                  LATCbits.LATC6
#define PORTC_LED_PORT                 PORTCbits.RC6
#define PORTC_LED_WPU                  WPUCbits.WPUC6
#define PORTC_LED_OD                   ODCONCbits.ODCC6
#define PORTC_LED_ANS                  ANSELCbits.ANSC6
#define PORTC_LED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define PORTC_LED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define PORTC_LED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define PORTC_LED_GetValue()           PORTCbits.RC6
#define PORTC_LED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define PORTC_LED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define PORTC_LED_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define PORTC_LED_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define PORTC_LED_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define PORTC_LED_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define PORTC_LED_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define PORTC_LED_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set PORTD_LED aliases
#define PORTD_LED_TRIS                 TRISCbits.TRISC7
#define PORTD_LED_LAT                  LATCbits.LATC7
#define PORTD_LED_PORT                 PORTCbits.RC7
#define PORTD_LED_WPU                  WPUCbits.WPUC7
#define PORTD_LED_OD                   ODCONCbits.ODCC7
#define PORTD_LED_ANS                  ANSELCbits.ANSC7
#define PORTD_LED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define PORTD_LED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define PORTD_LED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define PORTD_LED_GetValue()           PORTCbits.RC7
#define PORTD_LED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define PORTD_LED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define PORTD_LED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define PORTD_LED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define PORTD_LED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define PORTD_LED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define PORTD_LED_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define PORTD_LED_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/