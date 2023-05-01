/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"





int main() {
    Std_ReturnType ret = E_NOT_OK;
    uint8 value = 0;
    application_initialize();
    while (1) {
        ret = keypad_get_value(&keypad_1 ,&value);
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void){
    Std_ReturnType ret = E_OK;
    ecu_layer_initialize();
}