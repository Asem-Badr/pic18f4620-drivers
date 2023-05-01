/* 
 * File:   ecu_layer_init.c
 * Author: Asem
 *
 * Created on May 1, 2023, 2:35 AM
 */

#include "ecu_layer_init.h"


uint8 customChar[] = {
  0x0E,
  0x0A,
  0x11,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x00
};


chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.pin = PIN0,
    .lcd_rs.logic = LOW,
    
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.pin = PIN1,
    .lcd_en.logic = LOW,
    
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin  = PIN2,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = LOW,
    
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin  = PIN3,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = LOW,
    
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin  = PIN4,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = LOW,
    
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin  = PIN5,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = LOW,
    
};

chr_lcd_8bit_t lcd_2 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.pin = PIN6,
    .lcd_rs.logic = LOW,
    
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.pin = PIN7,
    .lcd_en.logic = LOW,
    
    .lcd_data[0].port = PORTD_INDEX,
    .lcd_data[0].pin  = PIN0,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = LOW,
    
    .lcd_data[1].port = PORTD_INDEX,
    .lcd_data[1].pin  = PIN1,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = LOW,
    
    .lcd_data[2].port = PORTD_INDEX,
    .lcd_data[2].pin  = PIN2,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = LOW,
    
    .lcd_data[3].port = PORTD_INDEX,
    .lcd_data[3].pin  = PIN3,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = LOW,
    
    .lcd_data[4].port = PORTD_INDEX,
    .lcd_data[4].pin  = PIN4,
    .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[4].logic = LOW,
    
    .lcd_data[5].port = PORTD_INDEX,
    .lcd_data[5].pin  = PIN5,
    .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[5].logic = LOW,
    
    .lcd_data[6].port = PORTD_INDEX,
    .lcd_data[6].pin  = PIN6,
    .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[6].logic = LOW,
    
    .lcd_data[7].port = PORTD_INDEX,
    .lcd_data[7].pin  = PIN7,
    .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[7].logic = LOW,
    
};

dc_motor_t dc_motor_1 = {
    .dc_motor[0].port = PORTC_INDEX,
    .dc_motor[0].pin = PIN0,
    .dc_motor[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[1].port = PORTC_INDEX,
    .dc_motor[1].pin = PIN1,
    .dc_motor[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT
};
dc_motor_t dc_motor_2 = {
    .dc_motor[0].port = PORTC_INDEX,
    .dc_motor[0].pin = PIN2,
    .dc_motor[0].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[1].port = PORTC_INDEX,
    .dc_motor[1].pin = PIN3,
    .dc_motor[1].logic = DC_MOTOR_OFF_STATUS,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT
};

keypad_t keypad_1 = {
    .keypad_rows_pins[0].port = PORTC_INDEX, 
    .keypad_rows_pins[0].pin = PIN0,
    .keypad_rows_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pins[0].logic = LOW,
    
    .keypad_rows_pins[1].port = PORTC_INDEX, 
    .keypad_rows_pins[1].pin = PIN1,
    .keypad_rows_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pins[1].logic = LOW,
    
    .keypad_rows_pins[2].port = PORTC_INDEX, 
    .keypad_rows_pins[2].pin = PIN2,
    .keypad_rows_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pins[2].logic = LOW,
    
    .keypad_rows_pins[3].port = PORTC_INDEX, 
    .keypad_rows_pins[3].pin = PIN3,
    .keypad_rows_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pins[3].logic = LOW,
    
    .keypad_columns_pins[0].port = PORTC_INDEX, 
    .keypad_columns_pins[0].pin = PIN4,
    .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[0].logic = LOW,
    
    .keypad_columns_pins[1].port = PORTC_INDEX, 
    .keypad_columns_pins[1].pin = PIN5,
    .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[1].logic = LOW,
    
    .keypad_columns_pins[2].port = PORTC_INDEX, 
    .keypad_columns_pins[2].pin = PIN6,
    .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[2].logic = LOW,
    
    .keypad_columns_pins[3].port = PORTC_INDEX, 
    .keypad_columns_pins[3].pin = PIN7,
    .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[3].logic = LOW
};


void ecu_layer_initialize(void){
    Std_ReturnType ret = E_OK;
    /*ret = lcd_4bit_initialize(&lcd_1);
    ret = lcd_8bit_initialize(&lcd_2);
    ret = dc_motor_initialize(&dc_motor_1);
    ret = dc_motor_initialize(&dc_motor_2);*/
    ret = keypad_initialize(&keypad_1);
}


/*ret = lcd_8bit_send_char_data(&lcd_2, 'A');
    ret = lcd_8bit_send_string(&lcd_2 , "Ahmed");
    ret = lcd_4bit_send_char_data(&lcd_1 , 'B');
    ret = lcd_4bit_send_char_data_pos(&lcd_1,2,4,'A');
    ret = lcd_4bit_send_string(&lcd_1,"asem");
    uint8 lcd_counter = ZERO_INIT;
    uint8 lcd_counter_txt [4];
    convert_byte_to_string(245,lcd_counter_txt);
    ret = lcd_4bit_send_string(&lcd_1,lcd_counter_txt);
    
    ret = lcd_4bit_send_custom_char(&lcd_1,2,2,customChar,0);*/

//ret = lcd_8bit_send_custome_char(&lcd_2,3,3,customChar,0);
        /*ret = dc_motor_move_right(&dc_motor_1);
        __delay_ms(500);
        ret = dc_motor_move_left(&dc_motor_1);
        __delay_ms(500);
        ret = dc_motor_stop(&dc_motor_1);
        __delay_ms(500);
        ret = dc_motor_move_right(&dc_motor_2);
        __delay_ms(500);
        ret = dc_motor_move_left(&dc_motor_2);
        __delay_ms(500);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(500);*/