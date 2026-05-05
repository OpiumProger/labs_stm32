#include "lab5_usart.h"
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef  hadc1;

/* Случай №2: глобальные static — видны только в этом файле */
static char tx_buf[256];
static char rx_byte  = 0;
volatile int uart_rx_flag = 0;

/* ── Инициализация ──────────────────────────────────────────── */
void plt_uart_init(void)
{
    plt_uart_send("\r\n=== ADC MONITOR ===\r\n");
    plt_uart_send("Commands:\r\n");
    plt_uart_send("  r -> Read ADC value\r\n");
    plt_uart_send("  s -> System status\r\n");
    plt_uart_send("===================\r\n");
    plt_uart_send("Waiting command: ");

    HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1);
}

/* ── Отправка строки ────────────────────────────────────────── */
void plt_uart_send(const char *data)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

/* ── Форматированный вывод ──────────────────────────────────── */
void plt_uart_print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsnprintf(tx_buf, sizeof(tx_buf), format, args);
    va_end(args);
    plt_uart_send(tx_buf);
}

/* ── Флаг приёма ────────────────────────────────────────────── */
int plt_uart_is_available(void)
{
    return uart_rx_flag;
}

/* ── Считать АЦП ────────────────────────────────────────────── */
static uint32_t read_adc(void)
{
    /* Случай №1: локальная static — счётчик сохраняется между вызовами */
    static int step_n = 0;
    step_n++;

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t val = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    plt_uart_print("\r\n[ADC] Read #%d  raw=%lu  voltage=%lu mV\r\n",
                   step_n, val, (val * 3300) / 4095);
    return val;
}

/* ── Обработка команды ──────────────────────────────────────── */
void plt_uart_process(void)
{
    if (!plt_uart_is_available()) return;

    uart_rx_flag = 0;

    plt_uart_send(&rx_byte);   /* эхо */

    if (rx_byte == 'r')
    {
        read_adc();
        plt_uart_send("Waiting command: ");
    }
    else if (rx_byte == 's')
    {
        uint32_t adc_val = read_adc();
        uint32_t uptime  = HAL_GetTick();

        plt_uart_print("--- System Status ---\r\n");
        plt_uart_print("Uptime : %lu ms\r\n", uptime);
        plt_uart_print("ADC    : %lu  (%lu mV)\r\n",
                       adc_val, (adc_val * 3300) / 4095);
        plt_uart_print("---------------------\r\nWaiting command: ");
    }
    else
    {
        if (rx_byte != '\r' && rx_byte != '\n')
        {
            plt_uart_send("\r\n[ERROR] Unknown command. Use r or s\r\nWaiting command: ");
        }
    }

    HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance != USART1) return;
    uart_rx_flag = 1;
}
