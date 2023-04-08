/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"
led_t led_1 = {
    .port = PORTC_INDEX,
    .pin = PIN0,
    .led_status = LED_ON
};
led_t led_2 = {
    .port = PORTC_INDEX,
    .pin = PIN1,
    .led_status = LED_ON
};
led_t led_3 = {
    .port = PORTC_INDEX,
    .pin = PIN2,
    .led_status = LED_ON
};
led_t led_4 = {
    .port = PORTC_INDEX,
    .pin = PIN3,
    .led_status = LED_ON
};


Std_ReturnType ret = E_NOT_OK;
int main() {
    
    application_initialize();
    while(1){
        led_turn_on(&led_1);
        __delay_ms(250);
        led_turn_off(&led_1);
        __delay_ms(250);
      
    }
    
    return (EXIT_SUCCESS);
}
void application_initialize(void){
    ret = led_initialize(&led_1);
    ret = led_initialize(&led_2);
    ret = led_initialize(&led_3);
    ret = led_initialize(&led_4);
}