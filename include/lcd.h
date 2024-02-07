/*********************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the STM32F103(blue pill) ARM CORTEXT M3/M4 LCD 16x2 driver
 *
 * Author: Mostafa Elsayed
 *
 *********************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "gpio.h"

// Lcd data pins should connected to port a from a0 to a7
// a8, a9 ,a10 ---> rs ,rw, e

//
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void LCD_initialization(void);
void LCD_cmd(uint8 data);
void LCD_write(uint8 data);

#endif /* LCD_H_ */
