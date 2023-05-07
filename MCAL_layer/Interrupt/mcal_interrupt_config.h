/* 
 * File:   mcal_interrupt_config.h
 * Author: Asem
 *
 * Created on May 2, 2023, 7:52 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section : Includes*/
#include <pic18f4620.h>
#include "../mcal_std_types.h"
#include "mcal_interrupt_gen_cfg.h"
/* Section : Macro Declarations */
#define INTERRUPT_ENABLE        1
#define INTERRUPT_DISABLE       0
#define INTERRUPT_OCCURED       1
#define INTERRUPT_NOT_OCCURED   0
#define INTERRUPT_PRIORITY_ENABLE   1
#define INTERRUPT_PRIORITY_DISABLE  0

/* Section: Macro functions Declarations */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_PriorityLevelsEnable() (RCONbits.IPEN = 1)

#define INTERRUPT_PriorityLevel_disable() (RCONbits.IPEN = 0)
/*this macro enables high priority global interrupts */
#define INTERRUPT_Global_InterruptHighEnable() (INTCONbits.GIEH = 1)
/*this macro disables high priority global interrupts */
#define INTERRUPT_Global_InterruptHighDisable() (INTCONbits.GIEH = 0)
/* */
#define INTERRUPT_Global_InterruptLowEnable() (INTCONbits.GIEL = 1)
/* */
#define INTERRUPT_Global_InterruptLowDisable() (INTCONbits.GIEL = 0)
#else
/* */
/*this macro enables global interrupts */
#define INTERRUPT_Global_InterruptEnable() (INTCONbits.GIE = 1)
/*this macro disables global interrupts */
#define INTERRUPT_Global_InterruptDisable() (INTCONbits.GIE = 0)
/* */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)
/* */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)

#endif

/* Section: Data Type Declarations */
typedef enum {
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY
} interrupt_priority_cfg;
/* Section: Function Declarations*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

