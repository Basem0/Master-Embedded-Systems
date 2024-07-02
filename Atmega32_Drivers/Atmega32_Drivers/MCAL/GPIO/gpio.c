/*
 * gpio.c
 *
 * Created: 7/2/2024 3:29:00 AM
 *  Author: ahmed
 */

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "gpio.h"

/************************************************************************/
/*                 Global Variables and Definitions                     */
/************************************************************************/

/* Reference to the Data Direction Control Registers */
vuint8_t *pin_registers[] = {PINA, PINB, PINC, PIND};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
vuint8_t *ddr_registers[] = {DDRA, DDRB, DDRC, DDRD};
/* Reference to the Port Status Register  */
vuint8_t *port_registers[] = {PORTA, PORTB, PORTC, PORTD};

/************************************************************************/
/*                      Function Implementations                        */
/************************************************************************/

/**
 * @brief Initialize the direction of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT:
                SET_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                CLR_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief Get the direction status of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param direction_status Pointer to store direction status
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status)
{
    Std_ReturnType ret = E_OK;
    if ((NULL == _pin_config) || (NULL == direction_status))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = GET_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * @brief Write logic level to a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param logic Logic level to be written (HIGH or LOW)
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (logic)
        {
            case GPIO_HIGH:
                SET_BIT(*port_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_LOW:
                CLR_BIT(*port_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief Read logic level from a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param logic Pointer to store read logic level
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic)
{
    Std_ReturnType ret = E_OK;
    if ((NULL == _pin_config) || (NULL == logic))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = GET_BIT(*pin_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * @brief Toggle logic level of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

/**
 * @brief Initialize a specific pin (direction and logic level)
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config)
{
    Std_ReturnType ret = E_OK;
    if ((NULL == _pin_config) || (_pin_config->pin > (PORT_PIN_MAX_NUMBER - 1)))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_intialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    return ret;
}

/**
 * @brief Initialize the direction of a specific port
 * 
 * @param port Port index
 * @param direction Direction value to be set for the port
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction)
{
    Std_ReturnType ret = E_OK;
    if (port > (PORT_MAX_NUMBER - 1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *ddr_registers[port] = direction;
    }
    return ret;
}

/**
 * @brief Get the direction status of a specific port
 * 
 * @param port Port index
 * @param direction_status Pointer to store direction status
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status)
{
    Std_ReturnType ret = E_OK;
    if ((port > (PORT_MAX_NUMBER - 1)) || (NULL == direction_status))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = *ddr_registers[port];
    }
    return ret;
}

/**
 * @brief Write logic level to a specific port
 * 
 * @param port Port index
 * @param logic Logic level to be written to the port
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *port_registers[port] = logic;
    }
    return ret;
}

/**
 * @brief Read logic level from a specific port
 * 
 * @param port Port index
 * @param logic Pointer to store read logic level
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
    Std_ReturnType ret = E_OK;
    if ((NULL == logic) && (port > PORT_MAX_NUMBER - 1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *port_registers[port];
    }
    return ret;
}

/**
 * @brief Toggle logic level of a specific port
 * 
 * @param port Port index
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *port_registers[port] ^= PORT_MASK;
    }
    return ret;
}
