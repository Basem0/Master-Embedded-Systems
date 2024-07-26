/*
 * BIT_utils.h

 *
 *  Created on: Jul 13, 2024
 *      Author: Ahmed Basem
 */

#ifndef LIB_BIT_UTILS_H_
#define LIB_BIT_UTILS_H_

#define SET_BIT(REG, BIT) REG |= (1 << BIT)
#define CLR_BIT(REG, BIT) REG &= ~(1 << BIT)
#define TGL_BIT(REG, BIT) REG ^= (1 << BIT)
#define GET_BIT(REG, BIT) ((REG >> BIT) & 1)

#define ASSIGN_BIT(REG, BIT, VALUE) \
if (VALUE)                      \
SET_BIT(REG, BIT);          \
else                            \
CLR_BIT(REG, BIT)

#define SET_REG(REG) REG = 0xFF
#define CLR_REG(REG) REG = 0x00
#define TGL_REG(REG) REG = ~REG
#define ASSIGN_REG(REG, VALUE) REG = VALUE

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* LIB_BIT_UTILS_H_ */





/*
 #define  x 5
 #define  y 4
 
 
#define conc(x,y)        conchelp(x,y)
conchelp(x,y)            x##y





1.        conc(x,y) >>>>> conchelp(x,y) >>>>>>>> conchelp(5,4) >>>>> 5##4 >>>> 54

*/


/*

 #define  x 5 
 #define  y 4
 
 #define conc(x,y)  x##y                        

int main()
{
	
	printf("%d",conc(x,y));
*/











