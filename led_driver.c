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

void LED_PWM_Start(TIM_HandleTypeDef* TIMER, uint16_t CHANNEL) {
	if(TIMER != NULL) {
		HAL_TIM_PWM_Start(TIMER, CHANNEL);
	}
}

void LED_PWM_Stop(TIM_HandleTypeDef* TIMER, uint16_t CHANNEL) {
	if(TIMER != NULL) {
		HAL_TIM_PWM_Stop(TIMER, CHANNEL);
	}
}

/**
 * @brief Set the LED brightness (duty cycle)
 * @param level brightness level. Value between 0 and 10 (0->off, 10->max brightness)
 */
void LED_SetBrightness(TIM_HandleTypeDef* TIMER, uint16_t CHANNEL, uint32_t level) {
	if(TIMER != NULL) {
		uint32_t _arr = TIMER->Instance->ARR;

		float _b = level / 10;
		uint32_t _ccr_val = _b * _arr; // convert to % of ARR

		// set brightness
		__HAL_TIM_SET_COMPARE(TIMER, CHANNEL, _ccr_val);

	} else {
		// todo: error handle
	}
}

/**
 * @brief Fade LED up and down
 * @param TIMER Timer used to generate the PWM
 * @param CHANNEL Timer channel being used to generate PWM
 * @param steps number of counts to increment or decrement the duty_cycle
 * @param delay_ms how much we should wait between each pulse. Higher value, LED fades slowly, Lower value, LED Fades quick
 *
 */
void LED_Fade(TIM_HandleTypeDef* TIMER, uint16_t CHANNEL,uint16_t steps, uint16_t delay_ms) {
	if(TIMER != NULL) {

		uint16_t _arr_val = TIMER->Instance->ARR;

		for(uint16_t h = 0; h < _arr_val; h += steps) {
			__HAL_TIM_SET_COMPARE(TIMER, CHANNEL, h);
			HAL_Delay(delay_ms);
		}

		for(uint16_t h = _arr_val; h > 0; h -= steps) {
			__HAL_TIM_SET_COMPARE(TIMER, CHANNEL, h);
			HAL_Delay(delay_ms);
		}

	} else {
		// todo: error handle
	}
}

