#include "lcd.h"
#include "gpio.h"
#include "external_interrupt.h"
#include "systick.h"
#include "common_macros.h"
#include "reg.h"
#include <libopencm3/stm32/exti.h>

typedef enum
{
    PAUSED,
    PLAYER1,
    PLAYER2,
    TIMEOUT
} Modes;

uint8 volatile player1_min = 9;
uint8 volatile player1_sec_1 = 5;
uint8 volatile player1_sec_2 = 9;

uint8 volatile player2_min = 9;
uint8 volatile player2_sec_1 = 5;
uint8 volatile player2_sec_2 = 9;

uint8 volatile state = PAUSED;
uint8 volatile lastTurn = PAUSED;
uint8 volatile lock = 0;
uint8 start = 1;
uint8 word[] = "TIMEOUT:";

void updatePlayer1()
{
    LCD_cmd(0x83);
    LCD_write(player1_min + '0');
    LCD_cmd(0x85);
    LCD_write(player1_sec_1 + '0');
    LCD_write(player1_sec_2 + '0');
}

void updatePlayer2()
{
    LCD_cmd(0x89);
    LCD_write(player2_min + '0');
    LCD_cmd(0x8B);
    LCD_write(player2_sec_1 + '0');
    LCD_write(player2_sec_2 + '0');
}

void print()
{
    LCD_cmd(0xC3);
    for (uint8 i = 0; i < 8; i++)
    {
        LCD_write(word[i]);
    }
}
void clear()
{
    LCD_cmd(0xC3);
    for (uint8 i = 0; i < 10; i++)
    {
        LCD_write(' ');
    }
}

int main(void)
{
    EXTERNAL_INTERRUPTS_init(PORTA, PIN8, RISING);  // First Button
    EXTERNAL_INTERRUPTS_init(PORTA, PIN9, RISING);  // Second Button
    EXTERNAL_INTERRUPTS_init(PORTA, PIN10, RISING); // Pause Button
    EXTERNAL_INTERRUPTS_init(PORTA, PIN11, RISING); // Reset Button

    LCD_initialization();  // Init LCD
    SYSTICK_initialize(1); // Init Systick Timer for 1sec
    LCD_cmd(0x84);
    LCD_write(':');
    LCD_cmd(0x8A);
    LCD_write(':');

    updatePlayer1();
    updatePlayer2();

    while (1)
        ;
}

void exti15_10_isr(void)
{
    // Pause Button
    if (READ_BIT(EXTI_PR, PIN10))
    {
        SET_BIT(EXTI_PR, PIN10);
        if (state == TIMEOUT)
            return;
        if (state == PAUSED)
        {
            state = lastTurn;
            lock = 0;
        }
        else
        {
            lastTurn = state;
            state = PAUSED;
            lock = 1;
        }
    }
    // Reset Button
    if (READ_BIT(EXTI_PR, PIN11))
    {
        SET_BIT(EXTI_PR, PIN11);
        player1_min = 9;
        player1_sec_1 = 5;
        player1_sec_2 = 9;
        player2_min = 9;
        player2_sec_1 = 5;
        player2_sec_2 = 9;
        state = PAUSED;
        lastTurn = PAUSED;
        start = 1;
        lock = 0;
        updatePlayer1();
        updatePlayer2();
        clear();
    }
}

void exti9_5_isr(void)
{

    // First Button
    if (READ_BIT(EXTI_PR, PIN8))
    {
        SET_BIT(EXTI_PR, PIN8);

        if (!lock && state != TIMEOUT)
        {
            if (start)
            {
                start = 0;
                SYSTICK_start();
            }
            state = PLAYER2;
        }
    }
    // Second Button
    if (READ_BIT(EXTI_PR, PIN9))
    {
        SET_BIT(EXTI_PR, PIN9);
        if (!lock && state != TIMEOUT)
        {
            if (start)
            {
                start = 0;
                SYSTICK_start();
            }
            state = PLAYER1;
        }
    }
}

// System timer
void sys_tick_handler(void)
{
    if (state == PAUSED || state == TIMEOUT)
        return;
    if (state == PLAYER1)
    {
        if (player1_sec_2 - 1 == -1)
        {
            player1_sec_2 = 9;
            if (player1_sec_1 - 1 == -1)
            {
                player1_sec_1 = 5;

                if (player1_min - 1 == -1)
                {
                    print();
                    LCD_write('P');
                    LCD_write('1');
                    state = TIMEOUT;
                    player1_sec_2 = 0;
                    player1_sec_1 = 0;
                }
                else
                    player1_min--;
            }
            else
                player1_sec_1--;
        }
        else
        {
            player1_sec_2--;
        }
        updatePlayer1();
    }
    if (state == PLAYER2)
    {
        if (player2_sec_2 - 1 == -1)
        {
            player2_sec_2 = 9;
            if (player2_sec_1 - 1 == -1)
            {
                player2_sec_1 = 5;

                if (player2_min - 1 == -1)
                {
                    print();
                    LCD_write('P');
                    LCD_write('2');
                    state = TIMEOUT;
                    player2_sec_2 = 0;
                    player1_sec_1 = 0;
                }
                else
                    player2_min--;
            }
            else
                player2_sec_1--;
        }
        else
        {
            player2_sec_2--;
        }
        updatePlayer2();
    }
}
