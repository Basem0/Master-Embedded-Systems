/*
 * UTILS.h
 *
 *  Created on: Jul 21, 2024
 *      Author: Ahmed Basem
 */

#ifndef LIBS_UTILS_H_
#define LIBS_UTILS_H_

#define	GET_BIT(REG, BIT)				((REG >> BIT) & 1)
#define SET_BIT(REG, BIT)				(REG |= (1 << BIT))
#define CLR_BIT(REG, BIT)				(REG &= ~(1 << BIT))
#define TOGGLE_BIT(REG, BIT)			(REG ^= (1 << BIT))

#define	GET_REG(REG)				(REG)
#define SET_REG(REG)				(REG = 0XFF)
#define CLR_REG(REG)				(REG = 0X00)
#define TOGGLE_REG(REG)				(REG ^= 0xFF)
#define ASSIGN_REG(REG, VALUE)		(REG = VALUE)

#define	GET_LOW_NIB(REG)			(REG & 0X0F)
#define SET_LOW_NIB(REG)			(REG |= 0X0F)
#define CLR_LOW_BIT(REG)			(REG &= 0XF0)
#define TOGGLE_LOW_NIB(REG)			(REG ^= 0X0F)
#define ASSIGN_LOW_NIB(REG, VALUE)	(REG = ((REG & 0XF0) | (VALUE & 0x0F)))

#define	GET_HIGH_NIB(REG)				((REG & 0XF0) >> 4)
#define SET_HIGH_NIB(REG)				(REG |= 0XF0)
#define CLR_HIGH_BIT(REG)				(REG &=0X0F)
#define TOGGLE_HIGH_NIB(REG)			(REG ^=0XF0)
#define ASSIGN_HIGH_NIB(REG, VALUE)		(REG = ((VALUE << 4) | (REG & 0X0F)))

#endif /* LIBS_UTILS_H_ */
