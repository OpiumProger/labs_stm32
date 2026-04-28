/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "main.h"
//#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */

int plt_init(void)
{
    return 0;
}

void plt_process(void)
{

	/* Устанавливаем задержку */
	plt_delay(500);

}
/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
