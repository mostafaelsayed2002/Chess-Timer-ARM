#include "gpio.h"
#include "common_macros.h"
#include "reg.h"

void GPIO_initialization(GPIO_Port port)
{
    switch (port)
    {
    case PORTA:
        SET_BIT(RCC_APB2ENR, IOPAEN);
        break;
    case PORTB:
        SET_BIT(RCC_APB2ENR, IOPBEN);
        break;
    case PORTC:
        SET_BIT(RCC_APB2ENR, IOPCEN);
        break;
    }
}

void GPIO_setupPinDirection(GPIO_Port port, GPIO_Pin pin, GPIO_Mode pin_mode, GPIO_Speed pin_speed)
{

    switch (port)
    {
    case PORTA:
        if (pin_speed == INPUT_MODE)
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOA_CRL, (pin * 4));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOA_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOA_CRL, (pin * 4));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOA_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 2));
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }

                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOA_CRL, (pin * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOA_CRL, (pin * 4));
                    SET_BIT(GPIOA_CRL, ((pin * 4) + 1));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOA_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOA_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 2));
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOA_CRH, ((pin - 8) * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOA_CRH, ((pin - 8) * 4));
                    SET_BIT(GPIOA_CRH, (((pin - 8) * 4) + 1));
                    break;
                default:
                    break;
                }
            }
        }
        break;
    case PORTB:
        if (pin_speed == INPUT_MODE)
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOB_CRL, (pin * 4));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOB_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOB_CRL, (pin * 4));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOB_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 2));
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }
                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOB_CRL, (pin * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOB_CRL, (pin * 4));
                    SET_BIT(GPIOB_CRL, ((pin * 4) + 1));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOB_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOB_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 2));
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOB_CRH, ((pin - 8) * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4)));
                    SET_BIT(GPIOB_CRH, (((pin - 8) * 4) + 1));
                    break;
                default:
                    break;
                }
            }
        }
        break;
    case PORTC:
        if (pin_speed == INPUT_MODE)
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOC_CRL, (pin * 4));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOC_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case INPUT_FLOATING:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 2));
                    break;
                case INPUT_INPUT_PUSH_PULL:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            if (pin <= PIN7)
            {
                CLEAR_BIT(GPIOC_CRL, (pin * 4));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 1));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 2));
                CLEAR_BIT(GPIOC_CRL, ((pin * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 2));
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 3));
                    break;
                default:
                    break;
                }
                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOC_CRL, (pin * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOC_CRL, (pin * 4));
                    SET_BIT(GPIOC_CRL, ((pin * 4) + 1));
                    break;
                default:
                    break;
                }
            }
            else
            {
                CLEAR_BIT(GPIOC_CRH, ((pin - 8) * 4));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 1));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 2));
                CLEAR_BIT(GPIOC_CRH, (((pin - 8) * 4) + 3));
                switch (pin_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 2));
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 3));
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 2));
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 3));
                    break;
                default:
                    break;
                }
                switch (pin_speed)
                {
                case SPEED_10_MHZ:
                    SET_BIT(GPIOC_CRH, ((pin - 8) * 4));
                    break;
                case SPEED_2_MHZ:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 1));
                    break;
                case SPEED_50_MHZ:
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4)));
                    SET_BIT(GPIOC_CRH, (((pin - 8) * 4) + 1));
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
}

void GPIO_writePin(GPIO_Port port, GPIO_Pin pin, uint8 value)
{
    switch (port)
    {
    case PORTA:
        if (value)
            SET_BIT(GPIOA_ODR, pin);
        else
            CLEAR_BIT(GPIOA_ODR, pin);
        break;
    case PORTB:
        if (value)
            SET_BIT(GPIOB_ODR, pin);
        else
            CLEAR_BIT(GPIOB_ODR, pin);
        break;
    case PORTC:
        if (value)
            SET_BIT(GPIOC_ODR, pin);
        else
            CLEAR_BIT(GPIOC_ODR, pin);
        break;
    }
}

uint8 GPIO_readPin(GPIO_Port port, GPIO_Pin pin_num)
{
    switch (port)
    {
    case PORTA:
        return READ_BIT(GPIOA_IDR, pin_num);
    case PORTB:
        return READ_BIT(GPIOB_IDR, pin_num);
    case PORTC:
        return READ_BIT(GPIOC_IDR, pin_num);
    default:
        return 0xff;
    }
}

void GPIO_setupPortDirection(GPIO_Port port, GPIO_Mode port_mode, GPIO_Speed port_speed)
{

    switch (port)
    {
    case PORTA:
        if (port_speed == INPUT_MODE)
        {
            switch (port_mode)
            {
            case INPUT_ANALOG:
                GPIOA_CRL = 0;
                GPIOA_CRH = 0;
                break;
            case INPUT_FLOATING:
                GPIOA_CRL = 0x44444444;
                GPIOA_CRH = 0x44444444;
                break;
            case INPUT_INPUT_PUSH_PULL:
                GPIOA_CRL = 0x88888888;
                GPIOA_CRH = 0x88888888;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (port_speed)
            {
            case SPEED_10_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOA_CRL = 0x11111111;
                    GPIOA_CRH = 0x11111111;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOA_CRL = 0x55555555;
                    GPIOA_CRH = 0x55555555;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOA_CRL = 0x99999999;
                    GPIOA_CRH = 0x99999999;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOA_CRL = 0xDDDDDDDD;
                    GPIOA_CRH = 0xDDDDDDDD;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_2_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOA_CRL = 0x22222222;
                    GPIOA_CRH = 0x22222222;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOA_CRL = 0x66666666;
                    GPIOA_CRH = 0x66666666;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOA_CRL = 0xAAAAAAAA;
                    GPIOA_CRH = 0xAAAAAAAA;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOA_CRL = 0xEEEEEEEE;
                    GPIOA_CRH = 0xEEEEEEEE;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_50_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOA_CRL = 0x33333333;
                    GPIOA_CRH = 0x33333333;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOA_CRL = 0x77777777;
                    GPIOA_CRH = 0x77777777;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOA_CRL = 0xBBBBBBBB;
                    GPIOA_CRH = 0xBBBBBBBB;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOA_CRL = 0xFFFFFFFF;
                    GPIOA_CRH = 0xFFFFFFFF;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        break;
    case PORTB:
        if (port_speed == INPUT_MODE)
        {
            switch (port_mode)
            {
            case INPUT_ANALOG:
                GPIOB_CRL = 0;
                GPIOB_CRH = 0;
                break;
            case INPUT_FLOATING:
                GPIOB_CRL = 0x44444444;
                GPIOB_CRH = 0x44444444;
                break;
            case INPUT_INPUT_PUSH_PULL:
                GPIOB_CRL = 0x88888888;
                GPIOB_CRH = 0x88888888;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (port_speed)
            {
            case SPEED_10_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOB_CRL = 0x11111111;
                    GPIOB_CRH = 0x11111111;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOB_CRL = 0x55555555;
                    GPIOB_CRH = 0x55555555;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOB_CRL = 0x99999999;
                    GPIOB_CRH = 0x99999999;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOB_CRL = 0xDDDDDDDD;
                    GPIOB_CRH = 0xDDDDDDDD;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_2_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOB_CRL = 0x22222222;
                    GPIOB_CRH = 0x22222222;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOB_CRL = 0x66666666;
                    GPIOB_CRH = 0x66666666;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOB_CRL = 0xAAAAAAAA;
                    GPIOB_CRH = 0xAAAAAAAA;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOB_CRL = 0xEEEEEEEE;
                    GPIOB_CRH = 0xEEEEEEEE;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_50_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOB_CRL = 0x33333333;
                    GPIOB_CRH = 0x33333333;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOB_CRL = 0x77777777;
                    GPIOB_CRH = 0x77777777;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOB_CRL = 0xBBBBBBBB;
                    GPIOB_CRH = 0xBBBBBBBB;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOB_CRL = 0xFFFFFFFF;
                    GPIOB_CRH = 0xFFFFFFFF;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        break;
    case PORTC:
        if (port_speed == INPUT_MODE)
        {
            switch (port_mode)
            {
            case INPUT_ANALOG:
                GPIOC_CRL = 0;
                GPIOC_CRH = 0;
                break;
            case INPUT_FLOATING:
                GPIOC_CRL = 0x44444444;
                GPIOC_CRH = 0x44444444;
                break;
            case INPUT_INPUT_PUSH_PULL:
                GPIOC_CRL = 0x88888888;
                GPIOC_CRH = 0x88888888;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (port_speed)
            {
            case SPEED_10_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOC_CRL = 0x11111111;
                    GPIOC_CRH = 0x11111111;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOC_CRL = 0x55555555;
                    GPIOC_CRH = 0x55555555;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOC_CRL = 0x99999999;
                    GPIOC_CRH = 0x99999999;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOC_CRL = 0xDDDDDDDD;
                    GPIOC_CRH = 0xDDDDDDDD;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_2_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOC_CRL = 0x22222222;
                    GPIOC_CRH = 0x22222222;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOC_CRL = 0x66666666;
                    GPIOC_CRH = 0x66666666;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOC_CRL = 0xAAAAAAAA;
                    GPIOC_CRH = 0xAAAAAAAA;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOC_CRL = 0xEEEEEEEE;
                    GPIOC_CRH = 0xEEEEEEEE;
                    break;
                default:
                    break;
                }
                break;
            case SPEED_50_MHZ:
                switch (port_mode)
                {
                case OUTPUT_GENERAL_PUSH_PULL:
                    GPIOC_CRL = 0x33333333;
                    GPIOC_CRH = 0x33333333;
                    break;
                case OUTPUT_GENERAL_OPEN_DRAIN:
                    GPIOC_CRL = 0x77777777;
                    GPIOC_CRH = 0x77777777;
                    break;
                case OUTPUT_ALTERNATE_PUSH_PULL:
                    GPIOC_CRL = 0xBBBBBBBB;
                    GPIOC_CRH = 0xBBBBBBBB;
                    break;
                case OUTPUT_ALTERNATE_OPEN_DRAIN:
                    GPIOC_CRL = 0xFFFFFFFF;
                    GPIOC_CRH = 0xFFFFFFFF;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        break;
    }
}

void GPIO_writePort(GPIO_Port port, uint16 value)
{
    switch (port)
    {
    case PORTA:
        GPIOA_ODR = value;
        break;
    case PORTB:
        GPIOB_ODR = value;
        break;
    case PORTC:
        GPIOC_ODR = value;
        break;
    default:
        break;
    }
}

uint16 GPIO_readPort(GPIO_Port port)
{
    switch (port)
    {
    case PORTA:
        return GPIOA_IDR;

    case PORTB:
        return GPIOB_IDR;

    case PORTC:
        return GPIOC_IDR;
    default:
        return 0xFFFF;
    }
}
