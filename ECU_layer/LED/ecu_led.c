/* 
 * File:   ecu_led.c
 * Author: Asem
 *
 * Created on March 24, 2023, 4:09 PM
 */

#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_initialize(const led_t *led) {
    Std_ReturnType ret = E_OK;

    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = led->port,
            .pin = led->pin,
            .logic = led->led_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_initialize(&pin_opject);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_on(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = led->port,
            .pin = led->pin,
            .logic = led->led_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_write_logic(&pin_opject, HIGH);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = led->port,
            .pin = led->pin,
            .logic = led->led_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_write_logic(&pin_opject, LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(const led_t *led) {
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_opject = {
            .port = led->port,
            .pin = led->pin,
            .logic = led->led_status,
            .direction = GPIO_DIRECTION_OUTPUT
        };
        ret = gpio_pin_toggle_logic(&pin_opject);
    }
    return ret;
}