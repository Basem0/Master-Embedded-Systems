/*
 * USART.h
 *
 * Created: 7/26/2024 3:42:12 AM
 *  Author: Ahmed Basem
 */ 


#ifndef USART_H_
#define USART_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "../includes/atmega32_device_header.h"
#include "../GPIO/GPIO.h"

/* ================================================================ */
/* ========== User type definitions (structures) ================== */
/* ================================================================ */

typedef struct{
	
	uint8 USART_Mode;					//specifies the mode of operation for USART (synchronous or asynchronous)
										//must be a value of @ref USART_MODE_define
	
	uint8 USART_Baudrate;				//specifies the baud rate which is used in transmitting and receiving
										//must be a value of @ref USART_BAUD_RATE_define

	uint8 USART_Databits;				//specifies the no. of data bits (5,6,7,8 or 9 bits)
										//must be a value of @ref USART_DATA_BITS_define

	uint8 USART_Paritybit;				//specifies the parity bit whether no parity, even parity or odd parity
										//must be a value of @ref USART_PARITY_BIT_define

	uint8 USART_Stopbits;				//specifies the no. of stop bits (1 or 2 bits)
										//must be a value of @ref USART_STOP_BITS_define

	uint8 USART_IRQ_Enable;				//specifies whether to enable interrupt or not
										//must be a value of @ref USART_IRQ_ENABLE_define
	
	void (*P_IRQ_CallBack)(void);		// Set the C Function() which will be called once the IRQ Happen

}USART_Config_t;


/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

/*
 * @ref USART_MODE_define
 */
#define USART_MODE_ASYNC				0
#define USART_MODE_SYNC					1

/*
 * @ref USART_BAUD_RATE_define
 * Baud rate (bps) @ f_osc = 8.0000MHz
				   @ U2X = 0 , Asynchronous Normal mode
 */
#define USART_BAUD_RATE_2400			207
#define USART_BAUD_RATE_4800			103
#define USART_BAUD_RATE_9600			51
#define USART_BAUD_RATE_14400			34
#define USART_BAUD_RATE_19200			25
#define USART_BAUD_RATE_28800			16
#define USART_BAUD_RATE_38400			12
#define USART_BAUD_RATE_57600			8
#define USART_BAUD_RATE_76800			6
#define USART_BAUD_RATE_115200			3
#define USART_BAUD_RATE_230400			1
#define USART_BAUD_RATE_250000			1

/*
 * @ref USART_DATA_BITS_define
 */
#define USART_5_DATA_BITS				0
#define USART_6_DATA_BITS				1
#define USART_7_DATA_BITS				2
#define USART_8_DATA_BITS				3
#define USART_9_DATA_BITS				4

/*
 * @ref USART_PARITY_BIT_define
 */
#define USART_NO_PARITY					0
#define USART_ODD_PARITY				1
#define USART_EVEN_PARITY				2

/*
 * @ref USART_STOP_BITS_define
 */
#define USART_1_STOP_BIT				0
#define USART_2_STOP_BIT				1

/*
 * @ref USART_IRQ_ENABLE_define
 */
#define USART_IRQ_DISABLE				0
#define USART_IRQ_TXCIE					1
#define USART_IRQ_RXCIE					2
#define USART_IRQ_TXCIE_RXCIE			3

enum Polling_Mechanism{
	USART_disable,
	USART_enable
};

/* ================================================================ */
/* ============== APIs Supported by "MCAL USART DRIVER" =========== */
/* ================================================================ */

void MCAL_USART_Init(USART_Config_t * PinConfig);
void MCAL_USART_DeInit(void);

void MCAL_UART_SendData(uint8 TxBuffer, enum Polling_Mechanism PollingEn);
uint16 MCAL_UART_ReceiveData(enum Polling_Mechanism PollingEn);

void MCAL_USART_SendString(uint8 *pTxBuffer);
void MCAL_USART_ReceiveString(uint8 *pRxBuffer);



#endif /* USART_H_ */