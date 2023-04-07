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
    .logic = HIGH
};
pin_config_t led_2 ={
    .port = PORTC_INDEX, 
    .pin = PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = LOW
};
pin_config_t led_3 ={
    .port = PORTC_INDEX, 
    .pin = PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = LOW
};
Std_ReturnType ret = E_NOT_OK;
direction_t led_1_st;
int main() {
    
    //ret = gpio_pin_direction_intialize(NULL);
    application_initialize();
    while(1){
        //gpio_pin_toggle_logic(&led_1);
        gpio_port_toggle_logic(PORTC_INDEX);
        __delay_ms(250);
      
    }
    
    return (EXIT_SUCCESS);
}
void application_initialize(void){
    ret = gpio_port_direction_intialize(PORTC_INDEX , 0x00);
    ret = gpio_port_write_logic(PORTC_INDEX , 0xAA);
}