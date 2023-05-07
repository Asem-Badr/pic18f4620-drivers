/* 
 * File:   mcal_external_interrupt.c
 * Author: Asem
 *
 * Created on May 2, 2023, 7:54 PM
 */

#include "mcal_external_interrupt.h"

static void (*INT0_interrupt_handler)(void) = NULL;
static void (*INT1_interrupt_handler)(void) = NULL;
static void (*INT2_interrupt_handler)(void) = NULL;

static Std_ReturnType interrupt_INTx_enable(const interrupt_INTx_t *interrupt_obj);
static Std_ReturnType interrupt_INTx_disable(const interrupt_INTx_t *interrupt_obj);
static Std_ReturnType interrupt_INTx_priority_init(const interrupt_INTx_t *interrupt_obj);
static Std_ReturnType interrupt_INTx_edge_init(const interrupt_INTx_t *interrupt_obj);
static Std_ReturnType interrupt_INTx_pin_init(const interrupt_INTx_t *interrupt_obj);
static Std_ReturnType interrupt_INTx_clear_flag(const interrupt_INTx_t *interrupt_obj);

static Std_ReturnType INT0_set_interrupt_handler(void (*interrupt_handler)(void));
static Std_ReturnType INT1_set_interrupt_handler(void (*interrupt_handler)(void));
static Std_ReturnType INT2_set_interrupt_handler(void (*interrupt_handler)(void));

static Std_ReturnType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *interrupt_obj);

static Std_ReturnType interrupt_RBTx_enable(const interrupt_RBx *interrupt_obj);
static Std_ReturnType interrupt_RBx_disable(const interrupt_RBx *interrupt_obj);
static Std_ReturnType interrupt_RBx_priority_init(const interrupt_RBx *interrupt_obj);
static Std_ReturnType interrupt_RBx_pin_init(const interrupt_RBx *interrupt_obj);

Std_ReturnType interrupt_INTx_init(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        /*disable the external interrupts*/
        ret = interrupt_INTx_disable(interrupt_obj);
        /*clear the interrupt flag*/
        interrupt_INTx_clear_flag(interrupt_obj);
        /*configure the interrupt edge*/
        ret = interrupt_INTx_edge_init(interrupt_obj);
        /*configure the interrupt priority*/
        #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        ret = interrupt_INTx_priority_init(interrupt_obj);
        #endif
        /*configure the external interrupt i/o pin*/
        ret = interrupt_INTx_pin_init(interrupt_obj);
        /*configure the interrupt callback*/
        ret = interrupt_INTx_set_interrupt_handler(interrupt_obj);
        /*enable the external interrupts*/
        ret = interrupt_INTx_enable(interrupt_obj);
    }
    return ret;
}

void INT0_ISR(void){
    /*clear the flag*/
    EXT_INT0_InterruptFlagClear();
    /*code to be executed*/
    
    /*callback function gets called every time this ISR executes */
    if(INT0_interrupt_handler){
        INT0_interrupt_handler();
    }
}
void INT1_ISR(void){
    /*clear the flag*/
    EXT_INT1_InterruptFlagClear();
    /*code to be executed*/
    
    /*callback function gets called every time this ISR executes */
    if(INT1_interrupt_handler){
        INT1_interrupt_handler();
    }
}
void INT2_ISR(void){
    /*clear the flag*/
    EXT_INT2_InterruptFlagClear();
    /*code to be executed*/
    
    /*callback function gets called every time this ISR executes */
    if(INT2_interrupt_handler){
        INT2_interrupt_handler();
    }
}
Std_ReturnType interrupt_INTx_deinit(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        ret = interrupt_INTx_disable(interrupt_obj);
    }
    return ret;
}

Std_ReturnType interrupt_RBx_init(const interrupt_RBx *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}

Std_ReturnType interrupt_RBx_deinit(const interrupt_RBx *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}

static Std_ReturnType interrupt_INTx_enable(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT0: 
                EXT_INT0_InterruptEnable();
                INTERRUPT_Global_InterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1: 
                EXT_INT1_InterruptEnable();
                INTERRUPT_Global_InterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2: 
                EXT_INT2_InterruptEnable();
                INTERRUPT_Global_InterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType interrupt_INTx_disable(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT0: EXT_INT0_InterruptDisable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1: EXT_INT1_InterruptDisable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2: EXT_INT2_InterruptDisable();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
static Std_ReturnType interrupt_INTx_priority_init(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT1:
                if(interrupt_obj->priority  == INTERRUPT_LOW_PRIORITY){
                    EXT_INT1_LOWPrioritySet();
                    ret = E_OK;
                }else if(interrupt_obj->priority  == INTERRUPT_HIGH_PRIORITY){ 
                    EXT_INT1_HighPrioritySet();
                    ret = E_OK;
                }else {
                    ret = E_NOT_OK;
                }
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if(interrupt_obj->priority  == INTERRUPT_LOW_PRIORITY){
                    EXT_INT2_LOWPrioritySet();
                    ret = E_OK;
                }else if(interrupt_obj->priority  == INTERRUPT_HIGH_PRIORITY){ 
                    EXT_INT2_HighPrioritySet();
                    ret = E_OK;
                }else {
                    ret = E_NOT_OK;
                }
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

static Std_ReturnType interrupt_INTx_edge_init(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT0: 
                if(INTERRUPT_FALLING_EDGE == interrupt_obj->edge){
                    EXT_INT0_FallingEdgeSet();
                    ret = E_OK;
                }else if(INTERRUPT_RISING_EDGE == interrupt_obj ->edge){
                    EXT_INT0_RisingEdgeSet();
                    ret = E_OK;
                }else{
                    ret = E_NOT_OK;
                }
                break;
            case INTERRUPT_EXTERNAL_INT1:
                if(INTERRUPT_FALLING_EDGE == interrupt_obj->edge){
                    EXT_INT1_FallingEdgeSet();
                    ret = E_OK;
                }else if(INTERRUPT_RISING_EDGE == interrupt_obj ->edge){
                    EXT_INT1_RisingEdgeSet();
                    ret = E_OK;
                }else{
                    ret = E_NOT_OK;
                }
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if(INTERRUPT_FALLING_EDGE == interrupt_obj->edge){
                    EXT_INT2_FallingEdgeSet();
                    ret = E_OK;
                }else if(INTERRUPT_RISING_EDGE == interrupt_obj ->edge){
                    EXT_INT2_RisingEdgeSet();
                    ret = E_OK;
                }else{
                    ret = E_NOT_OK;
                }
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType interrupt_INTx_pin_init(const interrupt_INTx_t *interrupt_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_direction_intialize(&(interrupt_obj->mcu_pin));
    }
    return ret;
}

static Std_ReturnType interrupt_INTx_clear_flag(const interrupt_INTx_t *interrupt_obj){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT0: EXT_INT0_InterruptFlagClear();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1: EXT_INT1_InterruptFlagClear();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2: EXT_INT2_InterruptFlagClear();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType INT0_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_handler) {
        ret = E_NOT_OK;
    } else {
        INT0_interrupt_handler = interrupt_handler;
        ret = E_OK;
    }
     return ret;
}
static Std_ReturnType INT1_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_handler) {
        ret = E_NOT_OK;
    } else {
        INT1_interrupt_handler = interrupt_handler;
        ret = E_OK;
    }
     return ret;
}
static Std_ReturnType INT2_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_handler) {
        ret = E_NOT_OK;
    } else {
        INT2_interrupt_handler = interrupt_handler;
        ret = E_OK;
    }
     return ret;
}

static Std_ReturnType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *interrupt_obj){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == interrupt_obj) {
        ret = E_NOT_OK;
    } else {
        switch (interrupt_obj->source) {
            case INTERRUPT_EXTERNAL_INT0: 
                ret = INT0_set_interrupt_handler(interrupt_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1: 
                ret = INT1_set_interrupt_handler(interrupt_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2: 
                ret = INT2_set_interrupt_handler(interrupt_obj->EXT_InterruptHandler);
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

