#include "led.h"
#include "stm32_regs.h"

#define GREEN_PIN 12U
#define BLUE_PIN  15U

void led_init(void)
{
    /* Enable GPIOD clock and allow the write to complete. */
    RCC_AHB1ENR |= (1UL << 3);
    (void)RCC_AHB1ENR;

    /* Start with both LEDs off. */
    GPIOD_BSRR = (1UL << (GREEN_PIN + 16U))
               | (1UL << (BLUE_PIN + 16U));

    /* Configure PD12 and PD15 as push-pull, low-speed outputs. */
    GPIOD_OTYPER &= ~((1UL << GREEN_PIN) | (1UL << BLUE_PIN));

    GPIOD_OSPEEDR &= ~((3UL << (GREEN_PIN * 2U))
                     | (3UL << (BLUE_PIN * 2U)));

    GPIOD_PUPDR &= ~((3UL << (GREEN_PIN * 2U))
                   | (3UL << (BLUE_PIN * 2U)));

    GPIOD_MODER &= ~((3UL << (GREEN_PIN * 2U))
                   | (3UL << (BLUE_PIN * 2U)));

    GPIOD_MODER |= (1UL << (GREEN_PIN * 2U))
                | (1UL << (BLUE_PIN * 2U));
}

void led_green_set(bool on)
{
    GPIOD_BSRR = on ? (1UL << GREEN_PIN)
                   : (1UL << (GREEN_PIN + 16U));
}

void led_blue_set(bool on)
{
    GPIOD_BSRR = on ? (1UL << BLUE_PIN)
                   : (1UL << (BLUE_PIN + 16U));
}