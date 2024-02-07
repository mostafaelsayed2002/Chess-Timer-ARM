

//================GPIO==================
#define RCC_APB2ENR (*(volatile uint32 *)0x40021018)
#define IOPAEN 2
#define IOPBEN 3
#define IOPCEN 4

#define GPIOA_CRL (*(volatile uint32 *)0x40010800)
#define GPIOB_CRL (*(volatile uint32 *)0x40010C00)
#define GPIOC_CRL (*(volatile uint32 *)0x40011000)

#define GPIOA_CRH (*(volatile uint32 *)0x40010804)
#define GPIOB_CRH (*(volatile uint32 *)0x40010C04)
#define GPIOC_CRH (*(volatile uint32 *)0x40011004)

#define GPIOA_IDR (*(volatile uint32 *)0x40010808)
#define GPIOB_IDR (*(volatile uint32 *)0x40010C08)
#define GPIOC_IDR (*(volatile uint32 *)0x40011008)

#define GPIOA_ODR (*(volatile uint32 *)0x4001080C)
#define GPIOB_ODR (*(volatile uint32 *)0x40010C0C)
#define GPIOC_ODR (*(volatile uint32 *)0x4001100C)

#define GPIOA_BSRR (*(volatile uint32 *)0x40010810)
#define GPIOB_BSRR (*(volatile uint32 *)0x40010C10)
#define GPIOC_BSRR (*(volatile uint32 *)0x40011010)

#define GPIOA_BRR (*(volatile uint32 *)0x40010814)
#define GPIOB_BRR (*(volatile uint32 *)0x40010C14)
#define GPIOC_BRR (*(volatile uint32 *)0x40011014)

//================External Interrupt==================

#define AFIO_EXTICR1 (*(volatile uint32 *)0x40010008)
#define AFIO_EXTICR2 (*(volatile uint32 *)0x4001000C)
#define AFIO_EXTICR3 (*(volatile uint32 *)0x40010010)
#define AFIO_EXTICR4 (*(volatile uint32 *)0x40010014)

#define EXTI_IMR (*(volatile uint32 *)0x40010400)
#define EXTI_EMR (*(volatile uint32 *)0x40010404)
#define EXTI_RTSR (*(volatile uint32 *)0x40010408)
#define EXTI_FTSR (*(volatile uint32 *)0x4001040C)
#define EXTI_PR (*(volatile uint32 *)0x40010414)

#define NVIC_ISER0 (*(volatile uint32 *)0xE000E100)
#define NVIC_ISER1 (*(volatile uint32 *)0xE000E104)
#define NVIC_ISER2 (*(volatile uint32 *)0xE000E108)
#define NVIC_ISER3 (*(volatile uint32 *)0xE000E10C)
#define NVIC_ISER4 (*(volatile uint32 *)0xE000E110)
#define NVIC_ISER5 (*(volatile uint32 *)0xE000E114)
#define NVIC_ISER6 (*(volatile uint32 *)0xE000E118)
#define NVIC_ISER7 (*(volatile uint32 *)0xE000E11C)

//================System Timer==================

#define SYST_CSR (*(volatile uint32 *)0xE000E010)

#define SYST_RVR (*(volatile uint32 *)0xE000E014)
#define SYST_CVR (*(volatile uint32 *)0xE000E018)
#define SYST_CALIB (*(volatile uint32 *)0xE000E01C)
