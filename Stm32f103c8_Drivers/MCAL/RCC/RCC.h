/*
 * RCC.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Ahmed Basem
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "STM32F103C8.h"
#include "GPIO.h"

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */
#define HSE_CLK 		(uint32)16000000
#define HSI_RC_CLK 		(uint32)8000000

/* ================================================================ */
/* =============== APIs Supported by "MCAL RCC DRIVER" ============ */
/* ================================================================ */
uint32 MCAL_RCC_GetSYS_CLKFreq(void);

uint32 MCAL_RCC_GetHCLKFreq(void);

uint32 MCAL_RCC_GetPCLK1Freq(void);
uint32 MCAL_RCC_GetPCLK2Freq(void);


#endif /* RCC_RCC_H_ */
