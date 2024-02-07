#include "lcd.h"
#include "gpio.h"
#include "common_macros.h"

// Lcd data pins should connected to port a from a0 to a7
// a8, a9 ,a10 ---> rs ,rw, e

void LCD_initialization(void)
{
    // Data or Instr
    GPIO_initialization(PORTA);
    GPIO_setupPinDirection(PORTA, PIN0, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN1, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN2, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN3, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN4, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN5, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN6, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTA, PIN7, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);

    // RS RW E
    GPIO_initialization(PORTB);
    GPIO_setupPinDirection(PORTB, PIN12, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTB, PIN13, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);
    GPIO_setupPinDirection(PORTB, PIN14, OUTPUT_GENERAL_PUSH_PULL, SPEED_10_MHZ);

    LCD_cmd(0x38);
    LCD_cmd(0x06);
    LCD_cmd(0x0C);
}

// Lcd data pins should connected to port a from a0 to a7
// a8 --> b15 , a9 ,a10 ---> rs ,rw, e
void LCD_cmd(uint8 data)
{
    GPIO_writePin(PORTA, PIN0, READ_BIT(data, 0));
    GPIO_writePin(PORTA, PIN1, READ_BIT(data, 1));
    GPIO_writePin(PORTA, PIN2, READ_BIT(data, 2));
    GPIO_writePin(PORTA, PIN3, READ_BIT(data, 3));
    GPIO_writePin(PORTA, PIN4, READ_BIT(data, 4));
    GPIO_writePin(PORTA, PIN5, READ_BIT(data, 5));
    GPIO_writePin(PORTA, PIN6, READ_BIT(data, 6));
    GPIO_writePin(PORTA, PIN7, READ_BIT(data, 7));
    // trun off Rs pin
    GPIO_writePin(PORTB, PIN12, 0);
    // trun on RW/Rs pin
    GPIO_writePin(PORTB, PIN13, 0);
    // trun on En pin
    GPIO_writePin(PORTB, PIN14, 1);
    // wait
    // for (uint64 i = 0; i < 2000; i++)
    // {
    // }
    // trun off En pin
    GPIO_writePin(PORTB, PIN14, 0);
}

void LCD_write(uint8 data)
{
    GPIO_writePin(PORTA, PIN0, READ_BIT(data, 0));
    GPIO_writePin(PORTA, PIN1, READ_BIT(data, 1));
    GPIO_writePin(PORTA, PIN2, READ_BIT(data, 2));
    GPIO_writePin(PORTA, PIN3, READ_BIT(data, 3));
    GPIO_writePin(PORTA, PIN4, READ_BIT(data, 4));
    GPIO_writePin(PORTA, PIN5, READ_BIT(data, 5));
    GPIO_writePin(PORTA, PIN6, READ_BIT(data, 6));
    GPIO_writePin(PORTA, PIN7, READ_BIT(data, 7));
    // trun off Rs pin
    // GPIO_writePin(PORTA, PIN8, 1);
    GPIO_writePin(PORTB, PIN12, 1);
    // trun on R/W pin
    GPIO_writePin(PORTB, PIN13, 0);
    // trun on En pin
    GPIO_writePin(PORTB, PIN14, 1);
    // wait
    // for (uint64 i = 0; i < 2000; i++)
    // {
    // }
    // trun off En pin
    GPIO_writePin(PORTB, PIN14, 0);
}
