/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"
void int0_application_isr(void);
void int1_application_isr(void);
void int2_application_isr(void);

interrupt_INTx_t int0_obj = {
    .EXT_InterruptHandler = int0_application_isr,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT0,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN0
};

interrupt_INTx_t int1_obj = {
    .EXT_InterruptHandler = int1_application_isr,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT1,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN1
};

interrupt_INTx_t int2_obj = {
    .EXT_InterruptHandler = int2_application_isr,
    .edge = INTERRUPT_RISING_EDGE,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .source = INTERRUPT_EXTERNAL_INT2,
    .mcu_pin.direction = GPIO_DIRECTION_INPUT,
    .mcu_pin.port = PORTB_INDEX,
    .mcu_pin.pin = PIN2
};

led_t led1 = {
    .led_status = LOW,
    .port = PORTC_INDEX,
    .pin = PIN0
};
led_t led2 = {
    .led_status = LOW,
    .port = PORTC_INDEX,
    .pin = PIN1
};
led_t led3 = {
    .led_status = LOW,
    .port = PORTC_INDEX,
    .pin = PIN2
};

int main() {
    Std_ReturnType ret = E_NOT_OK;
    uint8 value = 0;
    application_initialize();
    while (1) {

    }
    return (EXIT_SUCCESS);
}

void application_initialize(void) {
    Std_ReturnType ret = E_OK;
    ret = interrupt_INTx_init(&int0_obj);
    ret = interrupt_INTx_init(&int1_obj);
    ret = interrupt_INTx_init(&int2_obj);
    
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
}

void int0_application_isr(void) {
    led_toggle(&led1);
}

void int1_application_isr(void) {
    led_toggle(&led2);
}

void int2_application_isr(void) {
    led_toggle(&led3);
}