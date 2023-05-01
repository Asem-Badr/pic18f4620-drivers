/* 
 * File:   ecu_keypad.h
 * Author: Asem
 *
 * Created on May 1, 2023, 1:17 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes*/
#include "ecu_keypad_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/* Section : Macro Declarations */
#define ECU_KEYPAD_ROWS     4
#define ECU_KEYPAD_COLUMNS  4

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
typedef struct {
    pin_config_t keypad_rows_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/* Section: Function Declarations*/
Std_ReturnType keypad_initialize(const keypad_t *_keypad);
Std_ReturnType keypad_get_value(const keypad_t *_keypad ,uint8 *value);
#endif	/* ECU_KEYPAD_H */

