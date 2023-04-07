/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"


pin_config_t led_1 ={
    .port = PORTC_INDEX, 
    .pin = PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = LOW
};
int main() {
    gpio_pin_direction_intialize(&led_1);
    
    while(1){
      
    }
    
    return (EXIT_SUCCESS);
}

