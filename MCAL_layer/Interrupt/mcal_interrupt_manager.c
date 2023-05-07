/* 
 * File:   mcal_interrupt_manager.c
 * Author: Asem
 *
 * Created on May 2, 2023, 7:54 PM
 */

#include "mcal_interrupt_manager.h"

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
//__interrupt is called compiler qualifier
void __interrupt() interrupt_manager_high(void){
    
}
void __interrupt(low_priority) interrupt_manager_high(void){
    
}
#else 
void __interrupt() interrupt_manager_high(void){
    if((INTCONbits.INT0E == INTERRUPT_ENABLE)&&(INTERRUPT_OCCURED == INTCONbits.INT0IF)){
        INT0_ISR();
    }else{
        
    }
    if((INTCON3bits.INT1E == INTERRUPT_ENABLE)&&(INTERRUPT_OCCURED == INTCON3bits.INT1IF)){
        INT1_ISR();
    }else{
        
    }
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTERRUPT_OCCURED == INTCON3bits.INT2IF)){
        INT2_ISR();
    }else{
        
    }
}
#endif
    