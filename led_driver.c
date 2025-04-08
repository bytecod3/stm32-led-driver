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
 * LED variables
 */
uint8_t _s = 0;

/**
 * @brief Turn on LED connected to a GPIO pin
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_On(GPIO_TypeDef* PORT, uint16_t pin) {
	if(PORT !=  NULL) {
		HAL_GPIO_WritePin(PORT, pin, SET);
		_s = 1;
	} else {
		// todo: error handle
	}

}

/**
 * @brief Set the LED GPIO to unused state to release the peripheral if no longer needed
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Off(GPIO_TypeDef* PORT, uint16_t pin) {
	if(PORT != NULL) {
		HAL_GPIO_WritePin(PORT, pin, RESET);
		_s = 0;
	} else {
		// todo: error handle
	}

}

/**
 * @brief Set the LED GPIO to unused state to release the peripheral if no longer needed
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 */
void LED_Deinitialize(GPIO_TypeDef* PORT, uint16_t pin) {
	if(PORT != NULL) {
		HAL_GPIO_DeInit(PORT, pin);
	}
}

/**
 * @brief Blink the LED at the provided interval. This function is blocking. Calls `LED_On` and `LED_Off` internally
 * @param PORT GPIO PORT e.g GPIOA, GPIOC etc
 * @param pin led pin number. e.g (0,1, etc). Can also be a labeled pin name
 * @param interval how long to blink in milliseconds
 */
void LED_Blocking_Blink(GPIO_TypeDef* PORT, uint16_t pin, uint16_t interval) {
	if(PORT != NULL) {
		LED_On(PORT, pin);
		HAL_Delay(interval);
		LED_Off(PORT, pin);
		HAL_Delay(interval);
	} else {
		// todo: error handle
	}
}

void LED_Toggle(GPIO_TypeDef* PORT, uint16_t pin) {
	if(PORT != NULL) {
		if(_s) {
			LED_Off(PORT, pin);
		} else if(_s == 0) {
			LED_On(PORT, pin);
		}
	} else {
		// todo: error handle
	}
}

void LED_SetBrightness(TIM_TypeDef* TIMER, uint32_t brightness) {
	if(TIMER != NULL) {
		_brightness = brightness;
		if(TIMER == TIM1) {
			TIM1->CCR1 = _brightness;
		}

		if(TIMER == TIM2) {
			TIM2->CCR1 = _brightness;
		}

		if(TIMER == TIM3) {
			TIM3->CCR1 = _brightness;
		}

		if(TIMER == TIM4) {
			TIM4->CCR1 = _brightness;
		}

	} else {
		// todo: error handle
	}
}

/**
 * @brief Fade LED
 */
void LED_Fade(TIM_TypeDef* TIMER, uint16_t start, uint16_t stop) {
	if(TIMER != NULL) {

	} else {
		// todo: error handle
	}
}

