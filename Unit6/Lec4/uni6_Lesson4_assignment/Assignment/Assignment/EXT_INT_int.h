/*
 * EXT_INT_int.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_

/* Check Error Status */
typedef enum
{
  EXT_INT_OK,
  EXT_INT_NOK
}EXT_INT_tenuErrorStatus;

/* Macros for interrupts */
#define EXT_INT_u8_INT0        0
#define EXT_INT_u8_INT1        1
#define EXT_INT_u8_INT2        2

/* Macros for Sources */
#define EXT_INT_u8_RISING_EDGE_INT0             0X03
#define EXT_INT_u8_FALLING_EDGE_INT0            0x02
#define EXT_INT_u8_LOGICAL_CHANGE_INT0          0x01
#define EXT_INT_u8_LOW_LEVEL_INT0               0x00


#define EXT_INT_u8_CHECK_INT0(SOURCE)            (SOURCE==EXT_INT_u8_RISING_EDGE_INT0) || \
	                                        	 (SOURCE==EXT_INT_u8_FALLING_EDGE_INT0) || \
	                                        	 (SOURCE==EXT_INT_u8_LOGICAL_CHANGE_INT0) || \
	                                        	 (SOURCE==EXT_INT_u8_LOW_LEVEL_INT0)


#define EXT_INT_u8_RISING_EDGE_INT1             0X0C
#define EXT_INT_u8_FALLING_EDGE_INT1            0x08
#define EXT_INT_u8_LOGICAL_CHANGE_INT1          0x04
#define EXT_INT_u8_LOW_LEVEL_INT1               0x00

#define EXT_INT_u8_CHECK_INT1(SOURCE)            (SOURCE==EXT_INT_u8_RISING_EDGE_INT1) || \
	                                        	 (SOURCE==EXT_INT_u8_FALLING_EDGE_INT1) || \
	                                        	 (SOURCE==EXT_INT_u8_LOGICAL_CHANGE_INT1) || \
	                                        	 (SOURCE==EXT_INT_u8_LOW_LEVEL_INT1)


#define EXT_INT_u8_RISING_EDGE_INT2             0x40
#define EXT_INT_u8_FALLING_EDGE_INT2            0x00

#define EXT_INT_u8_CHECK_INT2(SOURCE)            (SOURCE==EXT_INT_u8_RISING_EDGE_INT2)  || \
	                                        	 (SOURCE==EXT_INT_u8_FALLING_EDGE_INT2)


/* Name:  EXT_INT_enuEnable
 * Discription:  enable bins for the external interrupt
 * Arguments:              First Argument: Copy_u8ExtPin         options(EXT_INT_u8_INT0,EXT_INT_u8_INT1,EXT_INT_u8_INT2)
 *                        Second Argument: Copy_u8Source         options:
 *               for INT0 and INT1(EXT_INT_u8_RISING_EDGE, EXT_INT_u8_FALLING_EDGE, EXT_INT_u8_LOGICAL_CHANGE ,EXT_INT_u8_LOW_LEVEL)
 *               for INT2(EXT_INT_u8_RISING_EDGE, EXT_INT_u8_FALLING_EDGE)
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuEnable(u8 Copy_u8ExtPin , u8 Copy_u8Source);


/* Name:  EXT_INT_enuDisable
 * Discription:  disable  the external interrupt
 * Arguments:               Copy_u8ExtPin         options(INT0,INT1,INT2)
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuDisable(u8 Copy_u8ExtPin);



/* Name:  EXT_INT_enuRegisterCBF
 * Discription:  Call back function of ISR
 * Arguments:                First Argument: Copy_u8ExtPin         options(INT0,INT1,INT2)
 *                          Second Argument: Add_pfuncCBF
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuRegisterCBF(u8 Copy_u8ExtPin , func_ptr Add_pfuncCBF);



#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
