/**
 * @file led_driver.c
 * @brief LED driver for STM32 micro-controllers
 * @author Edwin Mwiti
 * @license MIT
 */
#include <stdio.h>
#include <stdint.h>
#include "led_driver.h"

/**
 * @brief Turn on LED connected to a GPIO pin
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_On(GPIO_TypeDef* PORT, uint16_t pin) {
	HAL_GPIO_WritePin(PORT, pin, SET);
}

/**
 * @brief Set the LED GPIO to unused state to release the peripheral if no longer needed
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Off(GPIO_TypeDef* PORT, uint16_t pin) {
	HAL_GPIO_WritePin(PORT, pin, RESET);
}

/**
 * @brief Set the LED GPIO to unused state to release the peripheral if no longer needed
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Deinitialize(GPIO_TypeDef* PORT, uint16_t pin) {
	HAL_GPIO_DeInit(PORT, pin);
}

/**
 * @brief Blink the LED at the provided interval. This function is blocking. Calls `LED_On` and `LED_Off` internally
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 * @param interval how long to blink in milliseconds
 */
void LED_Blocking_Blink(GPIO_TypeDef* PORT, uint16_t pin, uint16_t interval) {
	LED_On(PORT, pin);
	HAL_Delay(interval);
	LED_Off(PORT, pin);
	HAL_Delay(interval);
}

