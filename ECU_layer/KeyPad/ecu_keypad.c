/* 
 * File:   ecu_keypad.c
 * Author: Asem
 *
 * Created on May 1, 2023, 1:17 AM
 */

#include "ecu_keypad.h"
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};

/**
 * 
 * @param _keypad
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad) {
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    if (NULL == _keypad) {
        ret = E_NOT_OK;
    } else {
        for (rows_counter = 0; rows_counter < ECU_KEYPAD_ROWS; rows_counter++) {
            ret = gpio_pin_initialize(&(_keypad->keypad_rows_pins[rows_counter]));
        }
        for (columns_counter = 0; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++) {
            ret = gpio_pin_initialize(&(_keypad->keypad_columns_pins[columns_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad, uint8 *value) {
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT, counter = ZERO_INIT;
    logic_t logic;
    if ((NULL == _keypad) || (NULL == value)) {
        ret = E_NOT_OK;
    } else {
        for (rows_counter = 0; rows_counter < ECU_KEYPAD_ROWS; rows_counter++) {
            for (counter = 0; counter < ECU_KEYPAD_ROWS; counter++) {
                gpio_pin_write_logic(&(_keypad->keypad_rows_pins[counter]), LOW);
            }
            gpio_pin_write_logic(&(_keypad->keypad_rows_pins[rows_counter]), HIGH);
            for (columns_counter = 0; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++) {
                ret = gpio_pin_read_logic(&(_keypad->keypad_columns_pins[columns_counter]), &logic);
                if (logic == HIGH) {
                    *value = btn_values[rows_counter][columns_counter];
                }
            }
        }
    }
    return ret;
}