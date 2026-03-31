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
#define tV_25   0.76f      // Напряжение (в вольтах) на датчике при температуре 25 °C.
#define tSlope  0.0025f    // �?зменение напряжения (в вольтах) при изменении температуры на градус.
#define Vref    3.3f       // Образцовое напряжение АЦП (в вольтах).
int16_t Result=0;
float temp;
char sprintf_buffer[100];


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
	/* Запуск TIM6 в режиме прерывания */
	if(HAL_ADC_PollForConversion(&hadc3, 100) == HAL_OK) return PLT_OK;
	else return PLT_ERROR;
}

uint32_t plt_adc_get_value(void)
{
	return HAL_ADC_GetValue(&hadc3);
}
