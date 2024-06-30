#include <stdint.h>
#include <stdio.h>
#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH   *(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIOA_ODR   *(volatile uint32_t *) (PORTA_BASE + 0x0C)

int main(void)
{
    RCC_APB2ENR |= 1<<2;
    // Configure PA11 as output (general purpose output push-pull, max speed 2 MHz)
    GPIOA_CRH &= 0xFF0FFFFF; // Clear bits 23-20 for PA11
    GPIOA_CRH |= 0x00200000; // Set mode to 0010: Output mode, max speed 2 MHz

    /* Loop forever */
    while (1)
    {
        GPIOA_ODR |= 1 << 13;  // Set PA13
        for (int i = 0; i < 100000; i++); // Delay
        GPIOA_ODR &= ~(1 << 13); // Clear PA13
        for (int i = 0; i < 100000; i++); // Delay
    }
}
