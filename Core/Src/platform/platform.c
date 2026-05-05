/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "main.h"
#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
#include "platform_def.h" 

extern UART_HandleTypeDef huart1;




/* Однократный вызов */
int plt_init(void)
{
	plt_timer_set(1500);
	plt_timer_start_irq();
    return 0;
}

void plt_timer_irq_cb(void){
	HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
}

int direction = 1;
int step_counter = 0;
int steps_per_rotation = 8;

void plt_process(void)
{
    uint32_t adc_value;
    float voltage;

    // Запуск АЦП
    plt_adc_start();

    if (plt_adc_conversion_poll() == PLT_OK)
    {
        adc_value = plt_adc_get_value();
        voltage = plt_adc_get_voltage();

        if (adc_value > 3000)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); 
        }
        else
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        }
    }

    // Останов АЦП
    plt_adc_stop();

    HAL_Delay(100);
}
