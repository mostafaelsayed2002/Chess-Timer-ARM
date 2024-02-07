/*********************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the STM32F103(blue pill) ARM CORTEXT M3/M4 GPIO driver
 *
 * Author: Mostafa Elsayed
 *
 *********************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define NUM_OF_PORTS 3 // A B C

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
    PORTA,
    PORTB,
    PORTC
} GPIO_Port;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} GPIO_Pin;

typedef enum
{
    INPUT_ANALOG,
    INPUT_FLOATING,
    INPUT_INPUT_PUSH_PULL,
    OUTPUT_GENERAL_PUSH_PULL,
    OUTPUT_GENERAL_OPEN_DRAIN,
    OUTPUT_ALTERNATE_PUSH_PULL,
    OUTPUT_ALTERNATE_OPEN_DRAIN
} GPIO_Mode;

typedef enum
{
    INPUT_MODE,
    SPEED_10_MHZ,
    SPEED_2_MHZ,
    SPEED_50_MHZ
} GPIO_Speed;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void GPIO_initialization(GPIO_Port port);
void GPIO_setupPinDirection(GPIO_Port port, GPIO_Pin pin, GPIO_Mode pin_mode, GPIO_Speed pin_speed);
void GPIO_writePin(GPIO_Port port, GPIO_Pin pin, uint8 value);
uint8 GPIO_readPin(GPIO_Port port, GPIO_Pin pin_num);

void GPIO_setupPortDirection(GPIO_Port port, GPIO_Mode port_mode, GPIO_Speed port_speed);
void GPIO_writePort(GPIO_Port port, uint16 value);
uint16 GPIO_readPort(GPIO_Port port);

#endif /* GPIO_H_ */