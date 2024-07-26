
//Learn-in-depth
//Seifeldin Ahmed Basem
//Mastering_EmbeddedSystem online diploma
typedef volatile unsigned int vuint32_t;

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

// register address
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL     *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

#define EXTI0_Base  0x40010400
#define EXTI0_IMR  *(volatile uint32_t *)(EXTI0_Base + 0x00)
#define EXTI0_RTSR *(volatile uint32_t *)(EXTI0_Base + 0x08)
#define EXTI0_PR   *(volatile uint32_t *)(EXTI0_Base + 0x14)

//AFIO
#define AFIO_BASE     0x40010000
#define AFIO_EXTICR1  *(volatile uint32_t *)(AFIO_BASE + 0x08)

//NVIC
#define NVIC_EXITE0   *(volatile uint32_t *)(0xE000E100)


void clock_init()
{
	// INIT CLOCK FOR GPIOA
	RCC_APB2ENR |= 1<<2;
	// Bit 0 AFION: Alternate function I/o clock enable
	RCC_APB2ENR |= 1<<0;
}

void GPIO_init()
{
	//pin 13 port A output
	 GPIOA_CRH &= 0xFF0FFFFF;
	 GPIOA_CRH |= 0x00200000;

	 // PIN A0: Floating input (reset state)
	 GPIOA_CRL |= (1<<2);
}

int main(void)
{
	clock_init();
	GPIO_init();

	//EXT0 for PORT A
	AFIO_EXTICR1 = 0 ;

	//Enable Rising Trigger
	EXTI0_RTSR |= (1<<0);

    //Enable EXIT line 0 (Mask 1)
	EXTI0_IMR |= (1<<0);

    //Enable NVIC IRQ6 >>> EXIT0
	NVIC_EXITE0 |= (1<<6);


	while(1);
}

void EXTI0_IRQHandler(void)
{
	//IRQ is Happened EXT0 >>> PORTA Pin 0 _| rising edge
	//toggle led pin A 13
	GPIOA_ODR ^= 1<<13 ;

	//clear Pending Request for line 0
	EXTI0_PR |= (1<<0);
}
