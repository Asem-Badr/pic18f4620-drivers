/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"

button_t btn_high = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = LOW,
    .button_pin.pin = PIN0,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
button_t btn_low = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = HIGH,
    .button_pin.pin = PIN1,
    .button_connection = BUTTON_ACTIVE_LOW,
    .button_state = BUTTON_RELEASED
};

led_t led_1 = {
    .led_status = LOW,
    .port = PORTC_INDEX,
    .pin = PIN0
};
led_t led_2 = {
    .led_status = LOW,
    .port = PORTC_INDEX,
    .pin = PIN1
};
relay_t relay_1 = {
    .relay_port = PORTC_INDEX ,
    .relay_pin = PIN0,
    .relay_status = RELEY_OFF_STATUS
};

Std_ReturnType ret = E_NOT_OK;
button_state_t button_high_state = BUTTON_RELEASED ;
button_state_t button_low_state = BUTTON_RELEASED ;
uint32 btn_high_valid = 0;
int main() {

    application_initialize();
    while (1) {
        ret = relay_turn_on(&relay_1);
        __delay_ms(250);
        ret = relay_turn_off(&relay_1);
        __delay_ms(250);
        
    }

    return (EXIT_SUCCESS);
}

void application_initialize(void) {
    ret = relay_initialize(&relay_1);
}