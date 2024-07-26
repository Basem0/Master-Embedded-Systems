
//Learn-in-depth
//Ahmed Basem
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
#define GPIOA_IDR     *(volatile uint32_t *)(GPIOA_BASE + 0x08)

// register address
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRL     *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH     *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR     *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR     *(volatile uint32_t *)(GPIOB_BASE + 0x08)

#define RCC_BASE    0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)


void clock_init()
{
	// INIT CLOCK FOR GPIOA
	RCC_APB2ENR |= 1<<2;

	// INIT CLOCK FOR GPIOB
	RCC_APB2ENR |= 1<<3;
}

void GPIO_init()
{
	GPIOA_CRL = 0x00;
	GPIOA_CRH = 0x00;
	GPIOB_CRL = 0x00;
	GPIOB_CRH = 0x00;

	// PA1 floating input
	GPIOA_CRL |= 1<<6;

	// PB1 output push pull mode (MAX SPEED 10MHZ)
	GPIOB_CRL |= (0b01 << 4);

    // PA13 floating input
	GPIOA_CRH |= 0x00400000;

	// PB13 output push pull mode (MAX SPEED 10MHZ)
	GPIOB_CRH |= (0b01<<20);
}
void wait(int x){
	unsigned int i , j;
	for(i=0 ; i < x ; i++)
		for(j=0; j < 255 ; j++);
}
int main(void)
{
	clock_init();
	GPIO_init();

	while(1){
       //PA1 >>> Connected by external PUR
	   if(((GPIOA_IDR >> 0x01) & 0X01) == 0 ) // single press
	   {
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR >> 0x01) & 0X01) == 0 );
	   }
       //PA13 >>> Connected by external PDR
	   if(((GPIOA_IDR >> 13) & 1) == 1 ) // Multi press
	   {
			GPIOB_ODR ^= 1<<13;
	   }
	   wait(1);
	}
}


