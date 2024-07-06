/*
 * stm32f103x6.h
 *
 *  Created on: July 3, 2024
 *      Author: Ahmed Basem
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

// =======================================================================================
// ===================================== INCLUDES ========================================
// =======================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Platform_Types.h"

#define F_CPU 10000000UL

// Base addresses for Memories
#define FLASH_Memory_BASE              0x08000000UL
#define System_Memory_BASE             0x1FFFF000UL
#define SRAM_BASE                      0x20000000UL
#define Peripherals_BASE               0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE  0xE0000000UL

// Base addresses for AHB Peripherals
#define RCC_BASE                       (Peripherals_BASE + 0x00021000UL)

// Base addresses for APB2 Peripherals
#define GPIOA_BASE                     (Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE                     (Peripherals_BASE + 0x00010C00UL)
#define GPIOC_BASE                     (Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE                     (Peripherals_BASE + 0x00011400UL)
#define GPIOE_BASE                     (Peripherals_BASE + 0x00011800UL)
#define AFIO_BASE                      (Peripherals_BASE + 0x00010000UL)
#define EXTI_BASE                      (Peripherals_BASE + 0x00010400UL)

// =======================================================================================
// ========================== Peripheral register: GPIO ==================================
// =======================================================================================
typedef struct {
	vuint32 CRL;
	vuint32 CRH;
	vuint32 IDR;
	vuint32 ODR;
	vuint32 BSRR;
    vuint32 BRR;
    vuint32 LCKR;
} GPIO_TypeDef;

// =======================================================================================
// ========================== Peripheral register: RCC ===================================
// =======================================================================================
typedef struct {
	vuint32 CR;
	vuint32 CFGR;
	vuint32 CIR;
	vuint32 APB2RSTR;
	vuint32 APB1RSTR;
	vuint32 AHBENR;
    vuint32 APB2ENR;
    vuint32 APB1ENR;
    vuint32 BDCR;
    vuint32 CSR;
    vuint32 AHBSTR;
    vuint32 CFGR2;
} RCC_TypeDef;

// =======================================================================================
// ========================== Peripheral register: EXTI ==================================
// =======================================================================================
typedef struct {
    vuint32 IMR;
    vuint32 EMR;
    vuint32 RTSR;
    vuint32 FTSR;
    vuint32 SWIER;
    vuint32 PR;
} EXTI_TypeDef;

// =======================================================================================
// ========================== Peripheral register: AFIO ==================================
// =======================================================================================
typedef struct {
    vuint32 EVCR;
    vuint32 MAPR;
    vuint32 EXTICR[4];
    uint32 RESERVED0;
    vuint32 MAPR2;
} AFIO_TypeDef;

// =======================================================================================
// ========================== Peripheral Instantnces == ==================================
// =======================================================================================
#define GPIOA                         ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                         ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                         ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                         ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                         ((GPIO_TypeDef *)GPIOE_BASE)
#define RCC                           ((RCC_TypeDef *)RCC_BASE)
#define AFIO                          ((AFIO_TypeDef *)AFIO_BASE)
#define EXTI                          ((EXTI_TypeDef *)EXTI_BASE)

// =======================================================================================
// =============================== Enable clock GPIO =====================================
// =======================================================================================
#define RCC_GPIOA_CLK_EN()            (RCC->APB2ENR |= (1 << 2))
#define RCC_GPIOB_CLK_EN()            (RCC->APB2ENR |= (1 << 3))
#define RCC_GPIOC_CLK_EN()            (RCC->APB2ENR |= (1 << 4))
#define RCC_GPIOD_CLK_EN()            (RCC->APB2ENR |= (1 << 5))
#define RCC_GPIOE_CLK_EN()            (RCC->APB2ENR |= (1 << 6))



#endif /* INC_STM32F103X6_H_ */
