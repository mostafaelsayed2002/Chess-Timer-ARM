/******************************************************************************
 *
 * Module: EXTERNAL INTERRRUPT
 *
 * File Name: interrupts.h
 *
 * Description: Header file for the STM32(blue pill) ARM Cortex M3 SYSTICK
 *
 * Author: Mostafa Elsayed
 *
 *******************************************************************************/

#ifndef _SYSTICK_H
#define _EXTERNAL_INTERRUPTS_H

#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void SYSTICK_initialize(uint32 second);
void SYSTICK_stop();
void SYSTICK_start();
void SYSTICK_reset();

#endif