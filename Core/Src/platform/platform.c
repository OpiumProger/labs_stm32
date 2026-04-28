/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
#include "main.h"
#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */
int plt_init(void)
{

	return 0;
}


/* Повторяющийся вызов */
void plt_process(void)
{
    int direction = 1;
    uint32_t last_step_time = 0;
    int step_count = 0;

    uint32_t current_time = HAL_GetTick();

    if (current_time - last_step_time >= 50) {
        plt_stepper(direction);
        last_step_time = current_time;
        step_count++;

        if (step_count >= 200) {
            direction = -direction;
            step_count = 0;
        }
    }
}

