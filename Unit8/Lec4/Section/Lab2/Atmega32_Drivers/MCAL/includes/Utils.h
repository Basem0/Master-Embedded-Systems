/*
 * Utils.h
 *
 * Created: 6/28/2024 12:25:50 AM
 *  Author: ahmed
 */

#ifndef UTILS_H_
#define UTILS_H_

/************************************************************************/
/*                         Bit Manipulation Macros                      */
/************************************************************************/

/* Get the value of a specific bit in a register */
#define GET_BIT(REG, BIT)            (((REG) >> (BIT)) & 1)

/* Set a specific bit in a register */
#define SET_BIT(REG, BIT)            (REG |= (1 << BIT))

/* Clear a specific bit in a register */
#define CLR_BIT(REG, BIT)            (REG &= ~(1 << BIT))

/* Toggle a specific bit in a register */
#define TOGGLE_BIT(REG, BIT)         (REG ^= (1 << BIT))

/************************************************************************/
/*                        Register Manipulation Macros                  */
/************************************************************************/

/* Get the value of a register */
#define GET_REG(REG)                 (REG)

/* Set all bits of a register to 1 */
#define SET_REG(REG)                 ((REG) = 0xFF)

/* Clear all bits of a register (set to 0) */
#define CLR_REG(REG)                 ((REG) = 0x00)

/* Toggle all bits of a register */
#define TOGGLE_REG(REG)              ((REG) ^= 0xFF)

/* Assign a specific value to a register */
#define ASSIGN_REG(REG, VALUE)       ((REG) = (VALUE))

/************************************************************************/
/*                     Low Nibble Manipulation Macros                   */
/************************************************************************/

/* Get the value of the low nibble (4 bits) of a register */
#define GET_LOW_NIB(REG)             ((REG) & 0x0F)

/* Set the low nibble (4 bits) of a register */
#define SET_LOW_NIB(REG)             ((REG) |= 0x0F)

/* Clear the low nibble (4 bits) of a register */
#define CLR_LOW_BIT(REG)             ((REG) &= 0xF0)

/* Toggle the low nibble (4 bits) of a register */
#define TOGGLE_LOW_NIB(REG)          ((REG) ^= 0x0F)

/* Assign a specific value to the low nibble (4 bits) of a register */
#define ASSIGN_LOW_NIB(REG, VALUE)   ((REG) = (((REG) & 0xF0) | ((VALUE) & 0x0F)))

/************************************************************************/
/*                     High Nibble Manipulation Macros                  */
/************************************************************************/

/* Get the value of the high nibble (4 bits) of a register */
#define GET_HIGH_NIB(REG)            (((REG) & 0xF0) >> 4)

/* Set the high nibble (4 bits) of a register */
#define SET_HIGH_NIB(REG)            ((REG) |= 0xF0)

/* Clear the high nibble (4 bits) of a register */
#define CLR_HIGH_BIT(REG)            ((REG) &= 0x0F)

/* Toggle the high nibble (4 bits) of a register */
#define TOGGLE_HIGH_NIB(REG)         ((REG) ^= 0xF0)

/* Assign a specific value to the high nibble (4 bits) of a register */
#define ASSIGN_HIGH_NIB(REG, VALUE)  ((REG) = ((VALUE << 4) | (REG & 0x0F)))

#endif /* UTILS_H_ */
