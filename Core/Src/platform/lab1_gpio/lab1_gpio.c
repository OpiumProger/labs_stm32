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

/* Функция инициализации пина светодиода */
void plt_gpio_init(void)
{
    /* Структура для настройки пина */
    GPIO_InitTypeDef GPIO_InitStruct = {0};


    /* Настройка пина как выхода */
    GPIO_InitStruct.Pin = LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  /* Выход push-pull */
    GPIO_InitStruct.Pull = GPIO_NOPULL;          /* Без подтяжки */
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; /* Низкая скорость */

    HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);
}

/* Функция переключения состояния светодиода */
void plt_gpio_toggle(void)
{
    /* Меняем состояние светодиода */
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
