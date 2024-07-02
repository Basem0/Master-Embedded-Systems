/*
 * keypad.h
 *
 * Created: 7/2/2024 6:37:00 PM
 *  Author: ahmed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/GPIO/gpio.h"

/************************************************************************/
/*                         Configuration Section                        */
/************************************************************************/

/* Define keypad types */
#define SMALL_PAD   0
#define BIG_PAD     1

/* Set the keypad type (SMALL_PAD or BIG_PAD) */
#define KEYPAD_TYPE SMALL_PAD

/* Define the number of rows in the keypad */
#define ECU_KEYPAD_ROWS     4

/* Define the number of columns based on the keypad type */
#if KEYPAD_TYPE == SMALL_PAD
    #define ECU_KEYPAD_COLUMNS  4
#endif

#if KEYPAD_TYPE == BIG_PAD
    #define ECU_KEYPAD_COLUMNS  6
#endif

/************************************************************************/
/*                     Data Type Declarations                           */
/************************************************************************/

/* Structure to represent the keypad configuration */
typedef struct {
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];    /* Array of row pins configuration */
    pin_config_t keypad_column_pins[ECU_KEYPAD_COLUMNS]; /* Array of column pins configuration */
} keypad_t;

/************************************************************************/
/*                     Function Declarations                            */
/************************************************************************/

/**
 * @brief init the keypad by setting up the row and column pins.
 * 
 * @param _keypad_obj Pointer to the keypad configuration structure.
 * @return Std_ReturnType Returns E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType keypad_init(const keypad_t *_keypad_obj);

/**
 * @brief Get the value of the pressed key on the keypad.
 * 
 * @param _keypad_obj Pointer to the keypad configuration structure.
 * @param value Pointer to store the value of the pressed key.
 * @return Std_ReturnType Returns E_OK if successful, E_NOT_OK otherwise.
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif /* KEYPAD_H_ */
