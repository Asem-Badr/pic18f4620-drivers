/* 
 * File:   ecu_relay.c
 * Author: Asem
 *
 * Created on April 13, 2023, 10:54 PM
 */
#include "ecu_relay.h"

Std_ReturnType relay_initialize (const relay_t* _relay){
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_initialize(&pin_opject);
    }
    return ret;
}
Std_ReturnType relay_turn_on(const relay_t* _relay){
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_write_logic(&pin_opject,HIGH);
    }
    return ret;
}
Std_ReturnType relay_turn_off(const relay_t* _relay){
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .logic = _relay->relay_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_write_logic(&pin_opject,LOW);
    }
    return ret;
}
