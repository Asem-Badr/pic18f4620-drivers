/* 
 * File:   ecu_relay.h
 * Author: Asem
 *
 * Created on April 13, 2023, 10:54 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/* Section : Includes*/
#include "ecu_relay_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"

/* Section : Macro Declarations */
#define RELAY_ON_STATUS  0X01U
#define RELEY_OFF_STATUS 0X00U

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
typedef struct {
    uint8 relay_port :4;
    uint8 relay_pin :3;
    uint8 relay_status :1;
}relay_t;

/* Section: Function Declarations*/
Std_ReturnType relay_initialize (const relay_t* _relay);
Std_ReturnType relay_turn_on(const relay_t* _relay);
Std_ReturnType relay_turn_off(const relay_t* _relay);
#endif	/* ECU_RELAY_H */

