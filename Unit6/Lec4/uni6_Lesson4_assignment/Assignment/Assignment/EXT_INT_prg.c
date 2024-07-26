/*
 * EXT_INT_prg.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */

#include "STD_Types.h"
#include "EXT_INT_int.h"
#include "EXT_INT_prv.h"

/* Name:  EXT_INT_enuEnable
 * Discription:  enable bins for the external interrupt
 * Arguments:              First Argument: Copy_u8ExtPin         options(INT0,INT1,INT2)
 *                        Second Argument: Copy_u8Source         options:
 *                                                             for INT0 and INT1(Rising edge , Falling edge , Digital Change , Low Level)
 *                                                             for INT2(Rising edge , Falling edge)
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuEnable(u8 Copy_u8ExtPin , u8 Copy_u8Source)
{
	EXT_INT_tenuErrorStatus Local_enuErrorStatus = EXT_INT_OK;
	/* Check Arguments */
	if(Copy_u8ExtPin>EXT_INT_u8_INT2)
	{
		Local_enuErrorStatus=EXT_INT_NOK;
	}
	else
	{
      switch(Copy_u8ExtPin)
         {
              case EXT_INT_u8_INT0 :
            	       if((EXT_INT_u8_CHECK_INT0(Copy_u8Source)) == 0)
            	       {
            	    	   Local_enuErrorStatus=EXT_INT_NOK;
            	       }
            	       else
            	       {
               	  	       EXT_INT_u8_MCUCR_REG |=Copy_u8Source;
                           EXT_INT_u8_GICR_REG  |=0x40;    // enable INT0
            	       }

                        break;

              case EXT_INT_u8_INT1 :
            	        if((EXT_INT_u8_CHECK_INT1(Copy_u8Source)) == 0)
            	        {
            	        	 Local_enuErrorStatus=EXT_INT_NOK;
            	        }
            	        else
            	        {
                  	        EXT_INT_u8_MCUCR_REG |=Copy_u8Source;
                	        EXT_INT_u8_GICR_REG  |=0x80;   // enable INT1
            	        }

                        break;

              case EXT_INT_u8_INT2 :

            	        if((EXT_INT_u8_CHECK_INT2(Copy_u8Source)) == 0)
            	          {
            	          	 Local_enuErrorStatus=EXT_INT_NOK;
            	          }
            	        else
            	        {
           	  	                EXT_INT_u8_GICR_REG &= ~(1<<5);  //disable the Perihperal interrupt enable
          	                	EXT_INT_u8_MCUCSR_REG |=Copy_u8Source;   // change the interrupt to rising edge
                 	          	EXT_INT_u8_GIFR_REG |=0x20;     // Clear flag
            	   	           	EXT_INT_u8_GICR_REG |= 0x20;   // re-enable  the Perihperal interrupt enable
            	        }

  	                    break;
        }

	}
	return Local_enuErrorStatus;
}


/* Name:  EXT_INT_enuDisable
 * Discription:  disable  the external interrupt
 * Arguments:               Copy_u8ExtPin         options(INT0,INT1,INT2)
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuDisable(u8 Copy_u8ExtPin)
{
	EXT_INT_tenuErrorStatus Local_enuErrorStatus = EXT_INT_OK;
	/* Check Arguments */
	if(Copy_u8ExtPin>EXT_INT_u8_INT2)
	{
		Local_enuErrorStatus=EXT_INT_NOK;
	}
	else
	{
	      switch(Copy_u8ExtPin)
	         {
	              case EXT_INT_u8_INT0 :
	            	      EXT_INT_u8_GICR_REG  &=~(1<<6);    // disable INT0
	             	      EXT_INT_u8_MCUCR_REG &=(1<<0);
	             	      EXT_INT_u8_MCUCR_REG &=(1<<1);
	                            break;

	              case EXT_INT_u8_INT1 :
	            	      EXT_INT_u8_GICR_REG  &=~(1<<7);    // disable INT1
	             	      EXT_INT_u8_MCUCR_REG &=(1<<2);
	             	      EXT_INT_u8_MCUCR_REG &=(1<<3);
	                            break;

	              case EXT_INT_u8_INT2 :
	            	  EXT_INT_u8_GICR_REG  &=~(1<<5);    // disable INT2
	            	  EXT_INT_u8_MCUCSR_REG &=(1<<6);
	                        break;
	        }
	 }


	return Local_enuErrorStatus;
}


typedef struct
{
	func_ptr EXT_INT_pfunINT0; // void (*EXT_INT_pfunINT0)(void)
	func_ptr EXT_INT_pfunINT1;
	func_ptr EXT_INT_pfunINT2;

}EXT_INT_tstrISR;

EXT_INT_tstrISR EXT_INT_strISR;
/* Name:  EXT_INT_enuRegisterCBF
 * Discription:  Call back function of ISR
 * Arguments:                First Argument: Copy_u8ExtPin         options(INT0,INT1,INT2)
 *                          Second Argument: Add_pfuncCBF
 * Return: ErrorStatus>>>>>>   EXT_INT_OK , EXT_INT_NOK
 * */
EXT_INT_tenuErrorStatus EXT_INT_enuRegisterCBF(u8 Copy_u8ExtPin , func_ptr Add_pfuncCBF)
{
	EXT_INT_tenuErrorStatus  Local_enuErrorStatus = EXT_INT_OK;
	/* Check Arguments */
	if(Copy_u8ExtPin>EXT_INT_u8_INT2 || Add_pfuncCBF == NULL )
	{
		Local_enuErrorStatus=EXT_INT_NOK;
	}
	else
	{
	      switch(Copy_u8ExtPin)
		         {
		              case EXT_INT_u8_INT0 :
		            	  EXT_INT_strISR.EXT_INT_pfunINT0=Add_pfuncCBF;
		                            break;

		              case EXT_INT_u8_INT1 :
		            	  EXT_INT_strISR.EXT_INT_pfunINT1=Add_pfuncCBF;

		                            break;

		              case EXT_INT_u8_INT2 :
		            	  EXT_INT_strISR.EXT_INT_pfunINT2=Add_pfuncCBF;

		                        break;
		        }
	}
	return Local_enuErrorStatus;
}


 
 void __vector_1(void)     __attribute__((signal,used));
 void __vector_1(void)
 {
 	if( EXT_INT_strISR.EXT_INT_pfunINT0 !=NULL)
 		     EXT_INT_strISR.EXT_INT_pfunINT0();
 }

// 	ISR(INT1_VECT)
 void __vector_2(void)     __attribute__((signal,used));
 void __vector_2(void)
 {
 	if( EXT_INT_strISR.EXT_INT_pfunINT1 !=NULL)
     EXT_INT_strISR.EXT_INT_pfunINT1();
 }
//	ISR(INT2_VECT)
void __vector_3(void)     __attribute__((signal,used));
void __vector_3(void)
{
	if( EXT_INT_strISR.EXT_INT_pfunINT2 !=NULL)
		     EXT_INT_strISR.EXT_INT_pfunINT2();
}
