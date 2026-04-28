/* Директива препроцессора для подключения заголовочного файла */
#include "lab4_adc.h"

/* Подключение заголовочного файла с определениями, перечислениями и макросами */
#include "../platform_def.h"

/* Подключение заголовочного файла main.h
 * main.h в свою очередь подключает _hal.h" - файл
 * необходимый для работы с периферией МК stm32 */
#include "main.h"


/* объявление внешней переменной — сообщает компилятору, что переменная htimN типа TIM_HandleTypeDef
 * определена где-то в другом месте (в другом файле компиляции) и будет доступна на этапе линковки. */
extern ADC_HandleTypeDef hadc3;

#include <stdio.h>

#define Vref    3.3f       // Образцовое напряжение АЦП (в вольтах).


void plt_adc_start(void)
{
	HAL_ADC_Start(&hadc3); // Запуск АЦП.
}

void plt_adc_stop(void)
{
	 HAL_ADC_Stop(&hadc3); // Остановка АЦП.
}

int plt_adc_conversion_poll(void)
{
	if(HAL_ADC_PollForConversion(&hadc3, 100) == HAL_OK) return PLT_OK;
	else return PLT_ERROR;
}

uint32_t plt_adc_get_value(void)
{
	return HAL_ADC_GetValue(&hadc3);
}

/* Напишите функцию расчета напряжения на входе АЦП
 * Функция использует в теле plt_adc_get_value() или
 * принимает аргументом целое число - результат измерений с АЦП
 * Функция возвращает напряжение в вольтах*/
float plt_adc_get_voltage(void)
{
    float voltage = 0.00;
    return voltage;
}
