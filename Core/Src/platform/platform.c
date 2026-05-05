/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "main.h"
#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
#include "platform_def.h"  // правильный путь

extern UART_HandleTypeDef huart1;


void plt_process(void){
	HAL_Delay(500);
}

/* Однократный вызов */
int plt_init(void)
{
	plt_timer_set(1999);
	plt_timer_start_irq();
    return 0;
}

void plt_timer_irq_cb(void){
	HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
}
