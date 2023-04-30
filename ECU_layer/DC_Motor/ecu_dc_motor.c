/* 
 * File:   ecu_dc_motor.c
 * Author: Asem
 *
 * Created on April 30, 2023, 10:30 PM
 */

#include "ecu_dc_motor.h"



Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_initialize(&(_dc_motor->dc_motor[0]));
        ret = gpio_pin_initialize(&(_dc_motor->dc_motor[1]));
    }
    return ret;
}

Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[0]) , HIGH);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[1]) , LOW);
    }
    return ret;
}

Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[0]) , LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[1]) , HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[0]) , LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor[1]) , LOW);
    }
    return ret;
}