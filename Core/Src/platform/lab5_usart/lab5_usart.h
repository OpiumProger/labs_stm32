#ifndef LAB5_USART_H
#define LAB5_USART_H

void plt_uart_init(void);
void plt_uart_send(const char *data);
void plt_uart_print(const char *format, ...);
int plt_uart_is_available(void);
void plt_uart_proccess(void);

#endif
