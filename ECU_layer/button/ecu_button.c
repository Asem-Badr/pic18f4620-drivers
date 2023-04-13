/* 
 * File:   ecu_button.c
 * Author: Asem
 *
 * Created on April 10, 2023, 5:07 PM
 */


#include "ecu_button.h"

Std_ReturnType button_initialize(const button_t* button){
    Std_ReturnType ret = E_OK;
    if (NULL == button) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_direction_intialize(&(button->button_pin));
        
    }
    return ret;
}

Std_ReturnType button_read_state(const button_t* button , button_state_t *button_state){
    Std_ReturnType ret = E_OK;
    button_state_t button_status = BUTTON_RELEASED;
    logic_t pin_state = LOW;
    if (NULL == button || NULL == button_state) {
        ret = E_NOT_OK;
        
    } else {
        gpio_pin_read_logic(&(button ->button_pin),&pin_state);
        switch(button ->button_connection){
            case BUTTON_ACTIVE_HIGH:
                if(pin_state == HIGH){
                    *button_state = BUTTON_PRESSED;
                }else{
                    *button_state = BUTTON_RELEASED;
                }
                break;
            case BUTTON_ACTIVE_LOW:
                if(pin_state == LOW){
                    *button_state = BUTTON_PRESSED;
                }else{
                    *button_state = BUTTON_RELEASED;
                }
                break ;
            default :ret = E_NOT_OK;
            
        }
        
    }
    return ret;
}