/* 
 * File:   application.h
 * Author: Asem
 *
 * Created on March 24, 2023, 4:14 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes*/
#include "ECU_layer/ecu_layer_init.h"
#include "MCAL_layer/Interrupt/mcal_external_interrupt.h"
#include "ECU_layer/LED/ecu_led.h"
#include "ECU_layer/Button/ecu_button.h"
/* Section : Macro Declarations */

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
extern keypad_t keypad_1;
/* Section: Function Declarations*/
void application_initialize(void);

#endif	/* APPLICATION_H */

