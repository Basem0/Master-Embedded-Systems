/*
 * gpio.h
 *
 * Created: 7/2/2024 3:28:48 AM
 *  Author: ahmed
 */

#ifndef GPIO_H_
#define GPIO_H_

/************************************************************************/
/*                              Includes                                */
/************************************************************************/
#include "../includes/atmega32_device_header.h"

/************************************************************************/
/*                          Macro Declarations                          */
/************************************************************************/
#define PORT_PIN_MAX_NUMBER  8      /* Maximum number of pins per port */
#define PORT_MAX_NUMBER      4      /* Maximum number of ports */

#define BIT_MASK    (uint8)1        /* Bit mask for individual bit operations */
#define PORT_MASK   0xFF            /* Mask for entire port operations */

#define GPIO_PORT_HIGH 0xFF         /* Set all pins in a port to high */
#define GPIO_PORT_LOW  0             /* Set all pins in a port to low */

/************************************************************************/
/*                      Data Type Declarations                          */
/************************************************************************/
/* Logic level types */
typedef enum{
    GPIO_LOW = 0,    /* Logic Low */
    GPIO_HIGH        /* Logic High */
} logic_t;

/* Direction types */
typedef enum{
    GPIO_DIRECTION_INPUT = 0,  /* Input Direction */
    GPIO_DIRECTION_OUTPUT      /* Output Direction */
} direction_t;

/* Pin index types */
typedef enum{
    GPIO_PIN0 = 0,  /* Pin 0 */
    GPIO_PIN1,      /* Pin 1 */
    GPIO_PIN2,      /* Pin 2 */
    GPIO_PIN3,      /* Pin 3 */
    GPIO_PIN4,      /* Pin 4 */
    GPIO_PIN5,      /* Pin 5 */
    GPIO_PIN6,      /* Pin 6 */
    GPIO_PIN7       /* Pin 7 */
} pin_index_t;

/* Port index types */
typedef enum{
    PORTA_INDEX = 0,  /* Port A */
    PORTB_INDEX,      /* Port B */
    PORTC_INDEX,      /* Port C */
    PORTD_INDEX       /* Port D */
} port_index_t;

/* Pin configuration structure */
typedef struct{
    uint8 port : 3;      /* Port index, see @ref port_index_t */
    uint8 pin : 3;       /* Pin index, see @ref pin_index_t */
    uint8 direction : 1; /* Pin direction, see @ref direction_t */
    uint8 logic : 1;     /* Pin logic level, see @ref logic_t */
} pin_config_t;

/************************************************************************/
/*                     Function Declarations                            */
/************************************************************************/

/**
 * @brief init the direction of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_direction_init(const pin_config_t *_pin_config);

/**
 * @brief Get the direction status of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param direction_status Pointer to store direction status
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);

/**
 * @brief Write logic level to a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param logic Logic level to be written (HIGH or LOW)
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);

/**
 * @brief Read logic level from a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @param logic Pointer to store read logic level
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);

/**
 * @brief Toggle logic level of a specific pin
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);

/**
 * @brief init a specific pin (direction and logic level)
 * 
 * @param _pin_config Pointer to pin configuration structure
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_pin_init(const pin_config_t *_pin_config);

/**
 * @brief init the direction of a specific port
 * 
 * @param port Port index
 * @param direction Direction value to be set for the port
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction);

/**
 * @brief Get the direction status of a specific port
 * 
 * @param port Port index
 * @param direction_status Pointer to store direction status
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);

/**
 * @brief Write logic level to a specific port
 * 
 * @param port Port index
 * @param logic Logic level to be written to the port
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);

/**
 * @brief Read logic level from a specific port
 * 
 * @param port Port index
 * @param logic Pointer to store read logic level
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);

/**
 * @brief Toggle logic level of a specific port
 * 
 * @param port Port index
 * @return Std_ReturnType E_OK if successful, E_NOT_OK if error
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port);

#endif /* GPIO_H_ */
