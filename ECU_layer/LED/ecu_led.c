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
Std_ReturnType led_initialize(const led_t *led){
     Std_ReturnType ret = E_OK;
      if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
          
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_trun_on(const led_t *led){
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
          
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
          
    }
     return ret;
}
/**
 * 
 * @param led
 * @return 
 */
Std_ReturnType led_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;
    if (NULL == led || led ->pin > PORT_PIN_MAX_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
          
    }
     return ret;
}