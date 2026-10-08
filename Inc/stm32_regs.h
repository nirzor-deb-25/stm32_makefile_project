#ifndef STM32_REGS_H
#define STM32_REGS_H

#include <stdint.h>

#define REG32(address) (*(volatile uint32_t *)(address))

/* Peripheral clock control */
#define RCC_AHB1ENR     REG32(0x40023830UL)

/* GPIOA: USER button */
#define GPIOA_MODER     REG32(0x40020000UL)
#define GPIOA_PUPDR     REG32(0x4002000CUL)
#define GPIOA_IDR       REG32(0x40020010UL)

/* GPIOD: onboard LEDs */
#define GPIOD_MODER     REG32(0x40020C00UL)
#define GPIOD_OTYPER    REG32(0x40020C04UL)
#define GPIOD_OSPEEDR   REG32(0x40020C08UL)
#define GPIOD_PUPDR     REG32(0x40020C0CUL)
#define GPIOD_BSRR      REG32(0x40020C18UL)

/* Cortex-M4 SysTick */
#define SYSTICK_CTRL    REG32(0xE000E010UL)
#define SYSTICK_LOAD    REG32(0xE000E014UL)
#define SYSTICK_VAL     REG32(0xE000E018UL)

#endif