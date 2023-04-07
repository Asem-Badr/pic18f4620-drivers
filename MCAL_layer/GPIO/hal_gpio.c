/* 
 * File:   hal_gpio.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */

#include "hal_gpio.h"
volatile uint8 * tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 * lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 * port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config) {
        ret = E_NOT_OK;
    } else {
        switch (_pin_config->direction) {
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_registers[_pin_config->port], _pin_config ->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_registers[_pin_config->port], _pin_config ->pin);
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

Std_ReturnType gpio_pin_get_dirction_status(const pin_config_t *_pin_config, direction_t dic_status) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == dic_status) {
        ret = E_NOT_OK;
    } else {
    }
return ret;

}

Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic) {
    Std_ReturnType ret = E_OK;

    return ret;

}

Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t logic) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic) {
    Std_ReturnType ret = E_OK;

    return ret;
}

Std_ReturnType gpio_port_toggle_logic(port_index_t port) {
    Std_ReturnType ret = E_OK;

    return ret;
}