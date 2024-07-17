# Unit 3: Learn In Depth Embedded Course

This repository contains the labs for Unit 3 of the Learn In Depth Embedded Course. Each folder corresponds to a specific lab exercise, focusing on different aspects of embedded systems programming.

## Folder Structure

1. **Lab 1: Toggle LED (STM32)**
   - This lab demonstrates how to toggle an LED using GPIO pins on an STM32 microcontroller.
   - Folder: `lab1_toggle_led_stm32`
   
2. **Lab 2: UART Driver (Tiva C)**
   - This lab focuses on writing a UART driver for the Tiva C microcontroller. It includes the assembly startup code and the linker script.
   - Folder: `lab2_uart_driver_tiva_c`

3. **Lab 3: Toggle LED (STM32 Blue Pill) with Assembly Startup**
   - This lab demonstrates how to toggle an LED using GPIO pins on the STM32 Blue Pill (STM32F103C8) microcontroller. It includes the assembly startup code, linker script, and a Makefile that generates a map file.
   - Folder: `lab3_toggle_led_stm32_asm`

4. **Lab 4: Toggle LED (STM32 Blue Pill) with Assembly and C Startup**
   - This lab demonstrates how to toggle an LED using GPIO pins on the STM32 Blue Pill (STM32F103C8) microcontroller. It includes both assembly and C startup code, linker script, and a Makefile that generates a map file.
   - Folder: `lab4_toggle_led_stm32_asm_c`

## Lab Descriptions

### Lab 1: Toggle LED (STM32)
- **Description:** This lab covers the basic operation of toggling an LED on an STM32 microcontroller using GPIO.
- **Files:**
  - `main.c`: Contains the main code to toggle the LED.
  - `Makefile`: Makefile to build the project.

### Lab 2: UART Driver (Tiva C)
- **Description:** This lab involves writing a UART driver for the Tiva C microcontroller. It includes the necessary assembly startup code and a linker script.
- **Files:**
  - `main.c`: Contains the main code for UART communication.
  - `uart_driver.c`: Implementation of the UART driver.
  - `uart_driver.h`: Header file for the UART driver.
  - `startup.s`: Assembly startup code.
  - `linker.ld`: Linker script.
  - `Makefile`: Makefile to build the project.

### Lab 3: Toggle LED (STM32 Blue Pill) with Assembly Startup
- **Description:** This lab demonstrates how to toggle an LED on the STM32 Blue Pill microcontroller. It includes an assembly startup file, linker script, and a Makefile that generates a map file.
- **Files:**
  - `main.c`: Contains the main code to toggle the LED.
  - `startup.s`: Assembly startup code.
  - `linker.ld`: Linker script.
  - `Makefile`: Makefile to build the project and generate a map file.

### Lab 4: Toggle LED (STM32 Blue Pill) with Assembly and C Startup
- **Description:** This lab demonstrates how to toggle an LED on the STM32 Blue Pill microcontroller. It includes both assembly and C startup files, linker script, and a Makefile that generates a map file.
- **Files:**
  - `main.c`: Contains the main code to toggle the LED.
  - `startup.s`: Assembly startup code.
  - `startup.c`: C startup code.
  - `linker.ld`: Linker script.
  - `Makefile`: Makefile to build the project and generate a map file.

