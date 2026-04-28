/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"


/* Однократный вызов */
int plt_init(void)
{
    return 0;
}

int direction = 1;
int step_counter = 0;
int steps_per_rotation = 8;

/* Повторяющийся вызов */
void plt_process(void)
{

    plt_stepper(direction);

    step_counter++;
    plt_delay(15);

    if (step_counter >= steps_per_rotation) {
       direction = -direction;
        step_counter = 0;

    }
}
/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
