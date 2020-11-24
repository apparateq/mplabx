// Copyright (C) 2020 Apparateq
//===----------------------------------------------------------------------===//
///
/// \file
///
/// \brief Pulse Width Modulation Demo
///
//===----------------------------------------------------------------------===//

#include "../mcc_generated_files/pin_manager.h"
#include "../mcc_generated_files/adc.h"
#include "../mcc_generated_files/pwm5.h"
#include "../mcc_generated_files/tmr2.h"

#include "../source/aptq_common.h"
#include "../source/aptq_pwm.h"

// Section: Local Function Prototypes
void PWM_Output_D7_Enable(void);
void PWM_Output_D7_Disable(void);

// Section: Local Variable Declarations
static uint16_t adcResult;

// Pulse Width Modulation Application
void PWM() {
    if (app_state == NOT_RUNNING) {
        PWM_Output_D7_Enable();
        TMR2_StartTimer();
        app_state = RUNNING;
    }

    if (app_state == RUNNING) {
        uint16_t adcResult = ADC_GetConversion(POT_CHANNEL) >> 6;
        PWM5_LoadDutyValue(adcResult);
    }

    if (app_change) {
        TMR2_StopTimer();
        PWM_Output_D7_Disable();
        app_state = NOT_RUNNING;
    }
}

void PWM_Output_D7_Enable(void) {
    // Set D7 as the output of PWM5
    RC5PPS = 0b00010;

}

void PWM_Output_D7_Disable(void) {
    // Restore D7 as a normal I/O pin
    RC5PPS = 0b00000;
}
