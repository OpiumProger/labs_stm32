#include "lab5_usart.h"
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;

static char tx_buf[256];
static char rx_byte = 0;

<<<<<<< HEAD
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


=======
volatile int uart_rx_flag = 0;
/* init UART и стартового меню */
void plt_uart_init(void)
{
    plt_uart_send("\r\n=== LED CONTROL ===\r\n");
    plt_uart_send("Enter 1 -> LED ON\r\n");
    plt_uart_send("Enter 0 -> LED OFF\r\n");
    plt_uart_send("==================\r\n");
    plt_uart_send("Waiting input: ");

    HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1); /* перезапуск приема след байта*/
}

/* send строки по UART */
>>>>>>> 5941d2524303cce44cec3d3fcd9f676acd43e7f4
void plt_uart_send(const char *data)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

<<<<<<< HEAD
=======
/* отформатированный вывод */
>>>>>>> 5941d2524303cce44cec3d3fcd9f676acd43e7f4
void plt_uart_print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsnprintf(tx_buf, sizeof(tx_buf), format, args);
    va_end(args);
    plt_uart_send(tx_buf);
}

<<<<<<< HEAD

=======
>>>>>>> 5941d2524303cce44cec3d3fcd9f676acd43e7f4
int plt_uart_is_available(void)
{
	return uart_rx_flag;
}

<<<<<<< HEAD
static uint32_t read_adc(void)
{
    static int step_n = 0;
    step_n++;
=======
void plt_uart_proccess(void)
{
	if(plt_uart_is_available())
	{
		uart_rx_flag = 0;
>>>>>>> 5941d2524303cce44cec3d3fcd9f676acd43e7f4

	    plt_uart_send(&rx_byte); /* отправка нажатого символа обратно */

<<<<<<< HEAD
    plt_uart_print("\r\n[ADC] Read #%d  raw=%lu  voltage=%lu mV\r\n",
                   step_n, val, (val * 3300) / 4095);
    return val;
}

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
=======
	    if (rx_byte == '1') /* если 1, то вкл */
	    {
	        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
	        plt_uart_send("\r\n[OK] LED ON\r\nWaiting input: ");
	    }
	    else if (rx_byte == '0') /* если 0, то выкл */
	    {
	        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
	        plt_uart_send("\r\n[OK] LED OFF\r\nWaiting input: ");
	    }
	    else
	    {
	        if (rx_byte != '\r' && rx_byte != '\n')
	        {
	            plt_uart_send("\r\n[ERROR] Use 1 or 0 only\r\nWaiting input: ");
	        }
	    }

	    HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1);
	}
>>>>>>> 5941d2524303cce44cec3d3fcd9f676acd43e7f4
}

/* колбэк при получении байта */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance != USART1) return;

    uart_rx_flag = 1;
}
