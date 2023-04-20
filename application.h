/* 
 * File:   application.h
 * Author: Asem
 *
 * Created on March 24, 2023, 4:14 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes*/
#include "ECU_layer/LED/ecu_led.h"
#include "ECU_layer/button/ecu_button.h"
#include "ECU_layer/Relay/ecu_relay.h"
#include "ECU_layer/Chr_LCD/ecu_chr_lcd.h"
/* Section : Macro Declarations */

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations*/
void application_initialize(void);

#endif	/* APPLICATION_H */

