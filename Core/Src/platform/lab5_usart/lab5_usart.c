/* Директива препроцессора для подключения заголовочного файла */

#include "lab5_usart.h"
#include "platform.h"
#include "stm32f1xx_hal.h"

static volatile uint8_t uart_rx_flag = 0;
static uint8_t rx_byte = 0;

// Счётчик обработанных команд – приватная глобальная static‑переменная
static uint32_t command_counter = 0;

// Внешний хендл UART (обычно объявлен в main.c)
extern UART_HandleTypeDef huart1;

/* ----------------------------------------------------------------
   Вспомогательная функция send_response
   (демонстрирует локальную static‑переменную)
   ---------------------------------------------------------------- */
static void send_response(uint8_t code, const char *msg)
{

    static uint32_t response_count = 0;
    response_count++;

    // Отправляем префикс с кодом
    plt_uart_send("\n[CODE: ");
    if (code == 0)
        plt_uart_send("0");
    else
        plt_uart_send("1");

    // Отправляем сообщение и информацию о счётчике ответов (для демонстрации static)
    plt_uart_send("] ");
    plt_uart_send(msg);
    plt_uart_send(" (response #");
    char buf[12];
    sprintf(buf, "%lu", response_count);
    plt_uart_send(buf);
    plt_uart_send(")\nWaiting input: ");
}

/* ================================================================
   Инициализация USART (не содержит static, но может быть вызвана
   лишь один раз при старте программы)
   ================================================================ */
void USART_Init(uint32_t baudrate)
{
    // В реальном коде здесь настройка HAL, сейчас заглушка
    // HAL_UART_Init(&huart1); ...
}

/* ================================================================
   Основной цикл опроса (вызывается из main или plt_process)
   Здесь с помощью static реализован КОНЕЧНЫЙ АВТОМАТ
   ================================================================ */
void USART_Process(void)
{
    // Локальная static‑переменная для конечного автомата обработки команд
    static enum {
        STATE_IDLE,
        STATE_WAIT_COMMAND
    } fsm_state = STATE_IDLE;

    // Проверяем, доступен ли принятый байт
    if (plt_uart_is_available()) {
        uart_rx_flag = 0;               // сбрасываем флаг
        plt_uart_send(&rx_byte);        // эхо только что принятого символа

        switch (fsm_state) {
            case STATE_IDLE:
                // Игнорируем всё, пока не начнём активный приём
                if (rx_byte != '\r' && rx_byte != '\n') {
                    fsm_state = STATE_WAIT_COMMAND;
                }
                break;

            case STATE_WAIT_COMMAND:
                if (rx_byte == '1') {
                    HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
                    send_response(0, "LED ON");
                    fsm_state = STATE_IDLE;
                    command_counter++;
                } else if (rx_byte == '0') {
                    HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
                    send_response(0, "LED OFF");
                    fsm_state = STATE_IDLE;
                    command_counter++;
                } else {
                    if (rx_byte != '\r' && rx_byte != '\n') {
                        send_response(1, "Use only 1 or 0");
                        fsm_state = STATE_IDLE;
                    }
                }
                break;
        }

        // Перезапускаем прерывание для приёма следующего байта
        HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) {
        uart_rx_flag = 1;
    }
}


uint32_t USART_GetCommandCount(void)
{
    return command_counter;
}
