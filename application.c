/* 
 * File:   application.c
 * Author: Asem
 *
 * Created on March 23, 2023, 2:09 PM
 */


#include "application.h"

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

Std_ReturnType ret = E_NOT_OK;

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
int main() {
    
    application_initialize();
    /*ret = lcd_8bit_send_char_data(&lcd_2, 'A');
    ret = lcd_8bit_send_string(&lcd_2 , "Ahmed");
    ret = lcd_4bit_send_char_data(&lcd_1 , 'B');
    ret = lcd_4bit_send_char_data_pos(&lcd_1,2,4,'A');
    ret = lcd_4bit_send_string(&lcd_1,"asem");*/
    uint8 lcd_counter = ZERO_INIT;
    uint8 lcd_counter_txt [4];
    convert_byte_to_string(245,lcd_counter_txt);
    ret = lcd_4bit_send_string(&lcd_1,lcd_counter_txt);
    
    ret = lcd_4bit_send_custom_char(&lcd_1,2,2,customChar,0);
    
    while (1) {
        ret = lcd_8bit_send_custome_char(&lcd_2,3,3,customChar,0);
        
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void) {
    ret = lcd_4bit_initialize(&lcd_1);
    ret = lcd_8bit_initialize(&lcd_2);
}