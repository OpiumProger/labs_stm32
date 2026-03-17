/* Директива препроцессора для подключения заголовочного файла */
#include "lab1_gpio.h"

/* Подключение заголовочного файла main.h
 * main.h в свою очередь подключает _hal.h" - файл
 * необходимый для работы с периферией МК stm32 */
#include "main.h"


/* Директива препроцессора - макроопределение
 * создаёт макрос (слева), который препроцессор заменяет на указанный справа текст */
#define LED_GPIO_Port	USER_LED_GPIO_Port
#define LED_Pin 		USER_LED_Pin

void plt_gpio_toggle(void)
{
	/* Меняем состояние светодиода */
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
