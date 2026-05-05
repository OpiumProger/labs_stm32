/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

#include "main.h"
#include "lab1_gpio/lab1_gpio.h"
#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
#include "lab5_usart/lab5_usart.h"
#include "platform_def.h"

extern UART_HandleTypeDef huart1;

/* Флаг для переключения состояния по таймеру */
volatile int timer_flag = 0;

/* Однокрачный вызов */
int plt_init(void)
{
    // Запуск 2-й лабораторной: инициализация и запуск таймера
    plt_timer_set(1000);  // Устанавливаем период 1000 (1 секунда при тактировании 1 кГц)
    if (plt_timer_start_irq() == PLT_OK)
    {
        // Таймер успешно запущен
        plt_uart_print("Timer started\r\n");
    }
    else
    {
        plt_uart_print("Timer start error\r\n");
    }

    return 0;
}

int direction = 1;
int step_counter = 0;
int steps_per_rotation = 8;

/* Колбэк от таймера (будет вызываться каждый период) */
void plt_timer_irq_cb(void)
{
    timer_flag = 1;  // Устанавливаем флаг для обработки в основном цикле
}

/* Повторяющийся вызов */
void plt_process(void)
{
    uint32_t adc_value;
    float voltage;

    // === ОБРАБОТКА ТАЙМЕРА (ЛАБА 2) ===
    if (timer_flag)
    {
        timer_flag = 0;

        // Переключаем состояние пина при срабатывании таймера
        static uint8_t led_state = 0;
        led_state = !led_state;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state);  // замени на свой LED пин

        // Вывод в UART (если запущена лаба 5)
        plt_uart_print("Timer IRQ! LED toggled, state: %d\r\n", led_state);
    }

    // === АЦП (ЛАБА 4) ===
    // Запуск АЦП
    plt_adc_start();

    // Ожидание преобразования
    if (plt_adc_conversion_poll() == PLT_OK)
    {
        // Получение значения
        adc_value = plt_adc_get_value();
        voltage = plt_adc_get_voltage();

        // Задание 1: проверка порога 3000
        if (adc_value > 3000)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);  // замени на свой LED пин
        }
        else
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        }
    }

    // Останов АЦП
    plt_adc_stop();

    // Задержка
    HAL_Delay(100);
}
