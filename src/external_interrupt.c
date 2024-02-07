
#include "external_interrupt.h"
#include "common_macros.h"
#include "reg.h"

void EXTERNAL_INTERRUPTS_init(GPIO_Port port, GPIO_Pin pin, EXTERNAL_INTERRUPTS_Modes mode)
{

    switch (port)
    {
    case PORTA:
        GPIO_initialization(PORTA);
        GPIO_setupPinDirection(PORTA, pin, INPUT_INPUT_PUSH_PULL, INPUT_MODE);
        if (pin <= PIN3 && pin >= PIN0)
        {
            CLEAR_BIT(AFIO_EXTICR1, (pin * 4));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 3));
        }
        if (pin >= PIN4 && pin <= PIN7)
        {
            CLEAR_BIT(AFIO_EXTICR2, ((pin - 4) * 4));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 3));
        }
        if (pin >= PIN8 && pin <= PIN11)
        {
            CLEAR_BIT(AFIO_EXTICR3, ((pin - 8) * 4));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 3));
        }
        if (pin >= PIN12 && pin <= PIN15)
        {
            CLEAR_BIT(AFIO_EXTICR4, ((pin - 12) * 4));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 3));
        }
        break;
    case PORTB:
        GPIO_initialization(PORTB);
        GPIO_setupPinDirection(PORTB, pin, INPUT_INPUT_PUSH_PULL, INPUT_MODE);
        if (pin >= PIN0 && pin <= PIN3)
        {
            SET_BIT(AFIO_EXTICR1, (pin * 4));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 3));
        }
        if (pin >= PIN4 && pin <= PIN7)
        {
            SET_BIT(AFIO_EXTICR2, ((pin - 4) * 4));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 3));
        }
        if (pin >= PIN8 && pin <= PIN11)
        {
            SET_BIT(AFIO_EXTICR3, ((pin - 8) * 4));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 3));
        }
        if (pin >= PIN12 && pin <= PIN15)
        {
            SET_BIT(AFIO_EXTICR4, ((pin - 12) * 4));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 3));
        }

        break;
    case PORTC:
        GPIO_initialization(PORTC);
        GPIO_setupPinDirection(PORTC, pin, INPUT_INPUT_PUSH_PULL, INPUT_MODE);
        if (pin >= PIN0 && pin <= PIN3)
        {
            CLEAR_BIT(AFIO_EXTICR1, (pin * 4));
            SET_BIT(AFIO_EXTICR1, ((pin * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR1, ((pin * 4) + 3));
        }
        if (pin >= PIN4 && pin <= PIN7)
        {
            CLEAR_BIT(AFIO_EXTICR2, ((pin - 4) * 4));
            SET_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR2, (((pin - 4) * 4) + 3));
        }
        if (pin >= PIN8 && pin <= PIN11)
        {
            CLEAR_BIT(AFIO_EXTICR3, ((pin - 8) * 4));
            SET_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR3, (((pin - 8) * 4) + 3));
        }
        if (pin >= PIN12 && pin <= PIN15)
        {
            CLEAR_BIT(AFIO_EXTICR4, ((pin - 12) * 4));
            SET_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 1));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 2));
            CLEAR_BIT(AFIO_EXTICR4, (((pin - 12) * 4) + 3));
        }
        break;
    }
    switch (pin)
    {
    case PIN0:
        SET_BIT(NVIC_ISER0, 6);
        break;
    case PIN1:
        SET_BIT(NVIC_ISER0, 7);
        break;
    case PIN2:
        SET_BIT(NVIC_ISER0, 8);
        break;
    case PIN3:
        SET_BIT(NVIC_ISER0, 9);
        break;
    case PIN4:
        SET_BIT(NVIC_ISER0, 10);
        break;
    case PIN5:
        SET_BIT(NVIC_ISER0, 23);
        break;
    case PIN6:
        SET_BIT(NVIC_ISER0, 23);
        break;
    case PIN7:
        SET_BIT(NVIC_ISER0, 23);
        break;
    case PIN8:
        SET_BIT(NVIC_ISER0, 23);
        break;
    case PIN9:
        SET_BIT(NVIC_ISER0, 23);
        break;
    case PIN10:
        SET_BIT(NVIC_ISER1, 8);
        break;
    case PIN11:
        SET_BIT(NVIC_ISER1, 8);
        break;
    case PIN12:
        SET_BIT(NVIC_ISER1, 8);
        break;
    case PIN13:
        SET_BIT(NVIC_ISER1, 8);
        break;
    case PIN14:
        SET_BIT(NVIC_ISER1, 8);
        break;
    case PIN15:
        SET_BIT(NVIC_ISER1, 8);
        break;
    }
    SET_BIT(EXTI_IMR, pin);
    if (mode == RISING)
        SET_BIT(EXTI_RTSR, pin);
    else
        SET_BIT(EXTI_FTSR, pin);
}

void EXTERNAL_INTERRUPTS_diable(GPIO_Pin pin)
{
    CLEAR_BIT(EXTI_IMR, pin);
}