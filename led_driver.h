/**
 * @file led_driver.h
 * @brief LED driver for STM32 micro-controllers
 * @author Edwin Mwiti
 * @date 2024-04-08
 * @license MIT
 */

//#include "stm32f4xx_hal.h"

#ifndef LED_DRIVER_H
#define LED_DRIVER_H
#include "stm32f4xx_hal.h" // change this to the stm32 you are using

/**
 * @brief Turn on LED connected to a GPIO pin
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_On(GPIO_TypeDef* PORT, uint16_t pin);

/**
 * @brief Turn off LED connected to GPIO pin
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Off(GPIO_TypeDef* PORT, uint16_t pin);

/**
 * @brief Set the LED GPIO to unused state to release the peripheral if no longer needed
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Deinitialize(GPIO_TypeDef* PORT, uint16_t pin);

/**
@brief Blink the LED at the provided interval. This function is blocking. Calls `LED_On` and `LED_Off` internally
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 * @param interval how long to blink in milliseconds
 */
void LED_Blocking_Blink(GPIO_TypeDef* PORT, uint16_t pin, uint16_t interval);

#endif
