/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"

int iter = 1;
int dir = 1;

int plt_init(void)
{
    return 0;
}

void plt_process(void)
{
    plt_stepper_full(iter);


    if (iter >= 4) {
        dir = -1;
    }
    if (iter <= 1) {
        dir = 1;
    }
    iter += dir;
    plt_delay(15);
}
/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
