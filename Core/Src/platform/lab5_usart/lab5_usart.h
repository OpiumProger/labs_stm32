/* #ifndef SRC_PLATFORM_LAB5_USART_LAB5_USART_H_
#define SRC_PLATFORM_LAB5_USART_LAB5_USART_H_



/* #endif /* SRC_PLATFORM_LAB5_USART_LAB5_USART_H_ */

#ifndef SRC_PLATFORM_LAB5_USART_LAB5_USART_H_
#define SRC_PLATFORM_LAB5_USART_LAB5_USART_H_

#include <stdint.h>
#include <stddef.h>

/* Инициализация USART */
void USART_Init(uint32_t baudrate);

/* Блокирующая отправка одного байта */
void USART_SendByte(uint8_t data);

/* Блокирующая отправка строки */
void USART_SendString(const char *str);

/* Неблокирующая отправка массива данных (возвращает число отправленных байт) */
size_t USART_SendData(const uint8_t *data, size_t len);

/* Приём одного байта с таймаутом (блокирующий) */
uint8_t USART_ReceiveByte(void);

/* Неблокирующий опрос приёма: обрабатывает поступающие байты,
   возвращает количество обработанных символов с момента последнего вызова */
size_t USART_Poll(void);

#endif /* SRC_PLATFORM_LAB5_USART_LAB5_USART_H_ */
