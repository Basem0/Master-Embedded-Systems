/*
 * EXT_INT_prv.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRV_H_
#define MCAL_EXT_INT_EXT_INT_PRV_H_

#define EXT_INT_u8_MCUCSR_REG                   (*(volatile u8*)0X54) // for INT2
#define EXT_INT_u8_MCUCR_REG                    (*(volatile u8*)0X55) // for INT0,INT1
#define EXT_INT_u8_GIFR_REG                     (*(volatile u8*)0X5A) // flag
#define EXT_INT_u8_GICR_REG                     (*(volatile u8*)0X5B) // PIE



#endif /* MCAL_EXT_INT_EXT_INT_PRV_H_ */
