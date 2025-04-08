# stm32-led-driver
LED driver for STM32 MCUs. 


# PWM control
## Brightness control
Configure the timer and set the timer channel in **PWM output mode**. You can follow this article for more information.
[STM32 PWM Example - Timer PWM Mode Tutorial (DeepBlue Embedded)](https://deepbluembedded.com/stm32-pwm-example-timer-pwm-mode-tutorial/)


To control the brightness, the ```CCR``` register is set to the value passed from the ```LED_SetBrightness()``` function.  
For any given timer , by default the ```ARR``` register is set to 65535, for no particular reason. This can be changed in the function 
call by passing the desired ARR value to the function, specifically to change the clock frequency.  
Alternatively, you can call the ```LED_Set_Frequency(uint16_t freq)``` function and pass a value between 0 and 65534. This functioni must be
called before ```LED_SetBrightness()```


Note, this driver assumes you are using the maximum timer bit resolution (16 bits). 

### Start timer
Start timer in PWM mode in ```main()```
````HAL_TIM_Start(&tim)``


## Usage Examples 
