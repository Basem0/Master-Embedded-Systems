/*
 * keypad.c
 *
 * Created: 7/2/2024 6:37:20 PM
 *  Author: ahmed
 */

#include "keypad.h"

#if KEYPAD_TYPE == SMALL_PAD
/* Button values for a small keypad (4x4) */
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};
#endif

#if KEYPAD_TYPE == BIG_PAD
/* Button values for a big keypad (4x6) */
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
    {'A', '7', '8', '9', '*', '/'},
    {'B', '4', '5', '6', '-', 'E'},
    {'C', '1', '2', '3', '+', 'F'},
    {'D', '0', '.', '=', '+', 'G'}
};
#endif

/************************************************************************/
/*                          Function Definitions                        */
/************************************************************************/

/**
 * @brief init the keypad pins.
 * 
 * This function inits the pins associated with the rows and columns
 * of the keypad.
 * 
 * @param _keypad_obj Pointer to the keypad object containing pin configurations.
 * @return Std_ReturnType Returns E_OK if initialization is successful, otherwise E_NOT_OK.
 */
Std_ReturnType keypad_init(const keypad_t *_keypad_obj)
{
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    Std_ReturnType ret = E_OK;
    
    if (NULL == _keypad_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* init row pins */
        for (rows_counter = ZERO_INIT; rows_counter < ECU_KEYPAD_ROWS; rows_counter++)
        {
            gpio_pin_init(&(_keypad_obj->keypad_row_pins[rows_counter]));
        }
        /* init column pins */
        for (columns_counter = ZERO_INIT; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++)
        {
            gpio_pin_init(&(_keypad_obj->keypad_column_pins[columns_counter]));
        }
    }
    
    return ret;
}

/**
 * @brief Get the value of the pressed key on the keypad.
 * 
 * This function scans the keypad and returns the value of the key that is pressed.
 * 
 * @param _keypad_obj Pointer to the keypad object containing pin configurations.
 * @param value Pointer to a variable where the pressed key value will be stored.
 * @return Std_ReturnType Returns E_OK if a key press is detected, otherwise E_NOT_OK.
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _keypad_obj) || (NULL == value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 l_rows_counter = ZERO_INIT, l_columns_counter = ZERO_INIT, l_counter = ZERO_INIT;
        uint8 column_logic = ZERO_INIT;
        
        for (l_rows_counter = ZERO_INIT; l_rows_counter < ECU_KEYPAD_ROWS; l_rows_counter++)
        {
            /* Set all rows to LOW */
            for (l_counter = ZERO_INIT; l_counter < ECU_KEYPAD_ROWS; l_counter++)
            {
                ret = gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter]), GPIO_LOW);
            }
            
            /* Set the current row to HIGH */
            gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_rows_counter]), GPIO_HIGH);
            
            /* Check each column for a HIGH signal */
            for (l_columns_counter = ZERO_INIT; l_columns_counter < ECU_KEYPAD_COLUMNS; l_columns_counter++)
            {
                ret = gpio_pin_read_logic(&(_keypad_obj->keypad_column_pins[l_columns_counter]), &column_logic);
                
                if (GPIO_HIGH == column_logic)
                {
                    *value = btn_values[l_rows_counter][l_columns_counter];
                    return ret; // Return immediately after finding the pressed key
                }
            }
        }
    }
    
    return ret;
}
