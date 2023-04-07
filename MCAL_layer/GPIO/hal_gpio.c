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
#if PROT_PIN_CONFIGRATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
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
#endif
/**
 * 
 * @param _pin_config
 * @param dic_status
 * @return 
 */
Std_ReturnType gpio_pin_get_dirction_status(const pin_config_t *_pin_config, direction_t *dic_status) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == dic_status || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        *dic_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config ->pin);
    }
    return ret;

}
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        switch(logic){
            case LOW :
                CLEAR_BIT(*lat_registers[_pin_config ->port], _pin_config ->pin);
                break;
            case HIGH :
                SET_BIT(*lat_registers[_pin_config ->port], _pin_config ->pin);
                break;
            default : ret = E_NOT_OK;
            
        }
    }

    return ret;

}
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == logic || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config ->pin);
    }



    return ret;
}
/**
 * 
 * @param _pin_config
 * @return 
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
            TOGGLE_BIT(*lat_registers[_pin_config ->port], _pin_config ->pin);
    }
    return ret;
}

/**
 * @brief initialize the direction of the pin and writes the initial logic on it
 * @param _pin_config : pointer to the configuration @ref pin_conf_t
 * @return Status of the function 
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function had issue while performing this action
 */
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_direction_intialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config , _pin_config ->logic);
            
        }
    return ret;
}


/**
 * 
 * @param port
 * @param direction
 * @return 
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction) {
    Std_ReturnType ret = E_OK;
    if(port >PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }else{
        *tris_registers[port] = direction;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param direction_status
 * @return 
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status) {
    Std_ReturnType ret = E_OK;
    if (NULL == direction_status || port >PORT_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    } else {
           *direction_status = *tris_registers[port];
    }
    return ret;
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic) {
    Std_ReturnType ret = E_OK;
    if(port >PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }else{
        *lat_registers[port] = logic;
    }
    return ret;
}
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic) {
    Std_ReturnType ret = E_OK;
    if (NULL == logic) {
        ret = E_NOT_OK;
    } else {
        *logic = lat_registers[port];
    }


    return ret;
}
/**
 * 
 * @param port
 * @return 
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port) {
    Std_ReturnType ret = E_OK;
    if(port >PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    }else{
        *lat_registers[port] ^= PORTC_MASK;
    }
    return ret;
}