/* 
 * File:   mcal_external_interrupt.h
 * Author: Asem
 *
 * Created on May 2, 2023, 7:54 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H


/* Section : Includes*/
#include "mcal_interrupt_config.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../GPIO/hal_gpio.h"
/* Section : Macro Declarations */
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXT_INT0_InterruptDisable() (INTCONbits.INT0IE = 0)

#define EXT_INT0_InterruptEnable() (INTCONbits.INT0IE = 1)

#define EXT_INT0_InterruptFlagClear() (INTCONbits.INT0IF = 0)

#define EXT_INT0_RisingEdgeSet() (INTCON2bits.INTEDG0 = 1)

#define EXT_INT0_FallingEdgeSet() (INTCON2bits.INTEDG0 = 0)


#define EXT_INT1_InterruptDisable() (INTCON3bits.INT1IE = 0)

#define EXT_INT1_InterruptEnable() (INTCON3bits.INT1IE = 1)

#define EXT_INT1_InterruptFlagClear() (INTCON3bits.INT1IF = 0)

#define EXT_INT1_RisingEdgeSet() (INTCON2bits.INTEDG1 = 1)

#define EXT_INT1_FallingEdgeSet() (INTCON2bits.INTEDG1 = 0)


#define EXT_INT2_InterruptDisable() (INTCON3bits.INT2IE = 0)

#define EXT_INT2_InterruptEnable() (INTCON3bits.INT2IE = 1)

#define EXT_INT2_InterruptFlagClear() (INTCON3bits.INT2IF = 0)

#define EXT_INT2_RisingEdgeSet() (INTCON2bits.INTEDG2 = 1)

#define EXT_INT2_FallingEdgeSet() (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE

#define EXT_INT1_HighPrioritySet() (INTCON3bits.INT1IP = 1)

#define EXT_INT1_LOWPrioritySet() (INTCON3bits.INT1IP = 0)

#define EXT_INT2_HighPrioritySet() (INTCON3bits.INT2IP = 1)

#define EXT_INT2_LOWPrioritySet() (INTCON3bits.INT2IP = 0)
#endif

#endif
#if EXTERNAL_INTERRUPT_onChange_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE

#define EXT_RBx_InterruptDisable() (INTCONbits.RBIE = 0)
#define EXT_RBx_InterruptEnable() (INTCONbits.RBIE = 1)
#define EXT_RBx_InterruptFlagClear() (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define EXT_RBx_Priority_High() (INTCON2bits.RBIP = 1)
#define EXT_RBx_priority_low() (INTCON2bits.RBIP = 0)
#endif

#endif
/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
typedef enum {
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
} interrupt_INTx_edge;

typedef enum {
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
} interrupt_INTx_src;

typedef struct {
    void(*EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
} interrupt_INTx_t;

typedef struct {
    void(*EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
} interrupt_RBx;

/* Section: Function Declarations*/
Std_ReturnType interrupt_INTx_init(const interrupt_INTx_t *interrupt_obj);
Std_ReturnType interrupt_INTx_deinit(const interrupt_INTx_t *interrupt_obj);
Std_ReturnType interrupt_RBx_init(const interrupt_RBx *interrupt_obj);
Std_ReturnType interrupt_RBx_deinit(const interrupt_RBx *interrupt_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

