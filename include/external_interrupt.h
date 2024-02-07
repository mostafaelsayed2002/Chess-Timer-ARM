/******************************************************************************
 *
 * Module: EXTERNAL INTERRRUPT
 *
 * File Name: interrupts.h
 *
 * Description: Header file for the STM32(blue pill) ARM Cortex M3 EXTERNAL INTERRRUPT
 *
 * Author: Mostafa Elsayed
 *
 *******************************************************************************/

#ifndef _EXTERNAL_INTERRUPTS_H
#define _EXTERNAL_INTERRUPTS_H

#include "gpio.h"
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
    FALLING,
    RISING
} EXTERNAL_INTERRUPTS_Modes;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void EXTERNAL_INTERRUPTS_init(GPIO_Port port, GPIO_Pin pin, EXTERNAL_INTERRUPTS_Modes mode);

void EXTERNAL_INTERRUPTS_diable(GPIO_Pin pin);

#endif