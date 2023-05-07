/* 
 * File:   mcal_interrupt_manager.h
 * Author: Asem
 *
 * Created on May 2, 2023, 7:54 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/* Section : Includes*/
#include "mcal_interrupt_config.h"

/* Section : Macro Declarations */

/* Section: Macro functions Declarations */

/* Section: Data Type Declarations */
 
/* Section: Function Declarations*/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

