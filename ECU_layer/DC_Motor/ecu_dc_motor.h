/* 
 * File:   ecu_dc_motor.h
 * Author: Asem
 *
 * Created on April 30, 2023, 10:30 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes*/
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"

/* Section : Macro Declarations */
#define DC_MOTOR_ON_STATUS  0X01U
#define DC_MOTOR_OFF_STATUS 0X00U

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */

typedef struct {
    uint8 dc_motor_port :4;
    uint8 dc_motor_pin :3;
    uint8 dc_motor_pin_status :1;
}dc_motor_pin_t;

typedef struct {
    pin_config_t dc_motor[2];
}dc_motor_t;

/* Section: Function Declarations*/
Std_ReturnType dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

