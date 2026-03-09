#ifndef SRC_PLATFORM_LAB2_TIMER_LAB2_TIMER_H_
#define SRC_PLATFORM_LAB2_TIMER_LAB2_TIMER_H_

#include <stdint.h>

/* Прототип колбэка, который сообщает компилятору: «где-то есть такая функция, её можно вызывать»*/
void plt_timer_irq_cb(void);

void plt_timer_set(uint32_t period);

int plt_timer_start_irq(void);

#endif /* SRC_PLATFORM_LAB2_TIMER_LAB2_TIMER_H_ */
