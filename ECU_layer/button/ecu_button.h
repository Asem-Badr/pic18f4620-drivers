/* 
 * File:   ecu_button.h
 * Author: Asem
 *
 * Created on April 10, 2023, 5:07 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section : Includes*/
#include "ecu_button_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/* Section : Macro Declarations */

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
typedef enum {
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_state_t;

typedef struct {
    pin_config_t button_pin ;
    button_state_t  button_state;
    button_active_state_t button_connection;
}button_t;
/* Section: Function Declarations*/
Std_ReturnType button_initialize(const button_t* button);
Std_ReturnType button_read_state(const button_t* button , button_state_t *button_state);
#endif	/* ECU_BUTTON_H */


