/*
 * atmega32_device_header.h
 *
 * Created: 7/2/2024 3:34:29 AM
 *  Author: Ahmed Basem
 */

#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_

/* ================================================================ */
/*                             Includes                             */
/* ================================================================ */
#include "Utils.h"           /* Utility macros and functions */
#include "Platform_Types.h"  /* Platform-specific type definitions */
#include <util/delay.h>

/* ================================================================ */
/* ========== Base Addresses of FLASH and SRAM memories =========== */
/* ================================================================ */
#define FLASH_MEMORY		0x00
#define SRAM				0x60

/* ================================================================ */
/* ================ Bus Peripheral Base Addresses ================= */
/* ================================================================ */
/* The Constant Difference between Memory Mapped Register Address  and  IO Mapped Register Address */
#define IO_MAPPING_OFFSET	0x20

#define GPIOA_Base			0x19	/* GPIO Port A address */
#define GPIOB_Base			0x16	/* GPIO Port B address */
#define GPIOC_Base			0x13	/* GPIO Port C address */
#define GPIOD_Base			0x10	/* GPIO Port D address */

#define USART_Base			0x09	/* USART address */
	
#define UCSRC_Base			0x20	/* USART Control and Status Register C address */
#define UBRRH_Base			0x20	/* USART Baud Rate Register High address */

#define SPI_Base			0x0D	/* SPI address */

#define TIMER0_Base			0x23	/* TIMER0 address */

#define TIFR_Base			0x36	/* Timer/Counter Interrupt Flag Register address */
#define TIMSK_Base			0x37	/* Timer/Counter Interrupt Mask Register address */

/* ================================================================ */
/* ================= Peripheral Registers GPIO ==================== */
/* ================================================================ */
typedef struct
{
	/* GPIO Input Pins Address */
	volatile union 
	{
		vuint8 PIN;		
		struct
		{
			vuint8 PIN0 :1;
			vuint8 PIN1 :1;
			vuint8 PIN2 :1;
			vuint8 PIN3 :1;
			vuint8 PIN4 :1;
			vuint8 PIN5 :1;
			vuint8 PIN6 :1;
			vuint8 PIN7 :1;
		}bits;
	}PIN;
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/

	/* GPIO Data Direction Register */
	volatile union 
	{
		vuint8 DDR;
		struct
		{
			vuint8 DD0 :1;
			vuint8 DD1 :1;
			vuint8 DD2 :1;
			vuint8 DD3 :1;
			vuint8 DD4 :1;
			vuint8 DD5 :1;
			vuint8 DD6 :1;
			vuint8 DD7 :1;
		}bits;
	}DDR;
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/

	/* GPIO Port Register */
	volatile union
	{
		vuint8 PORT;
		struct
		{
			vuint8 PORT0 :1;
			vuint8 PORT1 :1;
			vuint8 PORT2 :1;
			vuint8 PORT3 :1;
			vuint8 PORT4 :1;
			vuint8 PORT5 :1;
			vuint8 PORT6 :1;
			vuint8 PORT7 :1;
		}bits;
	}PORT;
	
}GPIO_Typedef_t;

/* ================================================================ */
/* ================ Peripheral Registers USART ==================== */
/* ================================================================ */

typedef struct{
	
	vuint8 UBRRL_;		/* USART Baud Rate Register Low, Address Offset: 0x09 */
		
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	/* USART Control and Status Register B */
	volatile union {
		vuint8 UCSRB_;
		struct {
			vuint8 TXB8_	  :1;		/* Transmit Data Bit 8 */
			vuint8 RXB8_ 	  :1;		/* Receive Data Bit 8 */
			vuint8 UCSZ2_   :1;		/* Character Size */
			vuint8 TXEN_    :1;		/* Transmitter Enable */
			vuint8 RXEN_    :1;		/* Receiver Enable */
			vuint8 UDRIE_   :1;		/* USART Data Register Empty Interrupt Enable */
			vuint8 TXCIE_   :1;		/* TX Complete Interrupt Enable */
			vuint8 RXCIE_   :1;		/* RX Complete Interrupt Enable */
		}bits;
	}UCSRB_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union 
	{
		vuint8 UCSRA_;		/* USART Control and Status Register A, Address Offset: 0x0B  */
		struct 
		{
			vuint8 MPCM_	    :1;		/* Multi-processor Communication Mode */
			vuint8 U2X_		:1;		/* Double the USART Transmission Speed */
			vuint8 PE_		:1;		/* Parity Error */
			vuint8 DOR_		:1;		/* Data OverRun */
			vuint8 FE_		:1;		/* Frame Error */
			vuint8 UDRE_	    :1;		/* USART Data Register Empty */
			vuint8 TXC_		:1;		/* USART Transmit Complete */
			vuint8 RXC_		:1;		/* USART Receive Complete */
		}bits;
	}UCSRA_;	
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8 UDR_;			/* USART I/O Data Register, Address Offset: 0x0C  */
			
}USART_Typedef_t;

/*
 * USART Control and Control Register C , Address Offset: 0x20 
 */
#define UCSRC			(*(vuint8*)(UCSRC_Base + IO_MAPPING_OFFSET))

#define UCPOL			0	/* Clock Polarity */
#define UCSZ0			1	/* Character Size */
#define UCSZ1			2	/* Character Size */
#define USBS			3	/* Stop Bit Select */
#define UPM0			4	/* Parity Mode */
#define UPM1			5	/* Parity Mode */
#define UMSEL			6	/* Mode Select */
#define URSEL			7	/* Register Select */

/* 
 * USART Baud Rate Register High , Address Offset: 0x20 
 */
#define UBRRH			(*(vuint8*)(UBRRH_Base + IO_MAPPING_OFFSET))	

/* ================================================================ */
/* ================ Peripheral Registers SPI ==================== */
/* ================================================================ */

typedef struct
{
	volatile union
	{
		vuint8 SPCR_;		/* SPI Control Register, Address Offset: 0x0D  */
		struct
		{
			vuint8 SPR0_	    :1;		/* SPI Clock Rate Select 0 */
			vuint8 SPR1_		:1;		/* SPI Clock Rate Select 1 */
			vuint8 CPHA_		:1;		/* Clock Phase */
			vuint8 CPOL_		:1;		/* Clock Polarity */
			vuint8 MSTR_		:1;		/* Master/Slave Select */
			vuint8 DORD_	    :1;		/* Data Order */
			vuint8 SPE_		:1;		/* SPI Enable */
			vuint8 SPIE_		:1;		/* SPI Interrupt Enable */
		}bits;
	}SPCR_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union
	{
		vuint8 SPSR_;		/* SPI Status Register, Address Offset: 0x0E  */
		struct
		{
			vuint8 SPI2X_	    :1;		/* Double SPI Speed Bit */
			vuint8 Reversed_	:5;		/* Reversed */
			vuint8 WCOL_		:1;		/* Write Collision Flag */
			vuint8 SPIF_		:1;		/* SPI Interrupt Flag */
		}bits;
	}SPSR_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8 SPDR_;		/*  SPI Data Register is a read/write register, Address Offset: 0x0F  */
		
}SPI_Typedef_t;

/* ================================================================ */
/* ================ Peripheral Registers TIMER0 =================== */
/* ================================================================ */
typedef struct
{
	vuint8 OCR0_;		/*  Output Compare Register, Address Offset: 0x23  */
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8 TCNT0_;		/* Timer/Counter Register, Address Offset: 0x24  */
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union
	{
		vuint8 TCCR0_;		/*  Timer/Counter Control Register, Address Offset: 0x25  */
		struct
		{
			vuint8 CS0n_	    :3;		/* Clock Select [n = 2:0] */
			vuint8 WGM01_		:1;		/* Waveform Generation Mode [n=0:1] */
			vuint8 COM0n_		:2;		/* Compare Match Output Mode [n = 1:0] */
			vuint8 WGM00_		:1;		/* Waveform Generation Mode */
			vuint8 FOC0_		:1;		/* Force Output Compare */
		}bits;
	}TCCR0_;
	
}TIMER0_Typedef_t;

/*
 * Timer/Counter Interrupt Mask Register , Address Offset: 0x37
 */
#define TIMSK			(*(vuint8*)(TIMSK_Base + IO_MAPPING_OFFSET))

#define TOIE0			0	/* Timer/CounterTimer/Counter0 Overflow Interrupt Enable */
#define OCIE0			1	/* Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable */

/*
 * Timer/Counter Interrupt Flag Register , Address Offset: 0x36
 */
#define TIFR			(*(vuint8*)(TIFR_Base + IO_MAPPING_OFFSET))

#define TOV0			0	/* Timer/Counter0 Overflow Flag */
#define OCF0			1	/* Output Compare Flag 0 */

/* ================================================================ */
/* =================== Peripheral Instants  ======================= */
/* ================================================================ */

/*-*-*-*-*-*-* GPIO_Instants *-*-*-*-*-*-*/

#define GPIOA			((GPIO_Typedef_t*) (GPIOA_Base + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_Base + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_Base + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* USART_Instants *-*-*-*-*-*-*/
#define USART			((USART_Typedef_t*) (USART_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* SPI_Instants *-*-*-*-*-*-*/
#define SPI				((SPI_Typedef_t*) (SPI_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* TIMER0_Instants *-*-*-*-*-*-*/
#define TIMER0			((TIMER0_Typedef_t*) (TIMER0_Base + IO_MAPPING_OFFSET))


/* ================================================================ */
/* ====================== Generic Macros  ========================= */
/* ================================================================ */

/*
 * Interrupt Macros
 */
#define SREG_Base		0x3F
#define SREG			(*(vuint8*)(SREG_Base + IO_MAPPING_OFFSET))
#define I_Bit			7

#define Enable_G_Interrupt()	SREG |= (1 << I_Bit)
#define Disable_G_Interrupt()	SREG &= ~(1 << I_Bit)

#endif /* ATMEGA32_DEVICE_HEADER_H_ */
