#ifndef SRC_PLATFORM_PLATFORM_H_
#define SRC_PLATFORM_PLATFORM_H_

/* Директива препроцессора для подключения заголовочного файла stdint.h для работы с типом uint32_t (см. plt_delay())
 * Угловые скобки — поиск начинается в системных (стандартных) каталогах включений
 * Используется для подключения стандартных библиотечных заголовков (как stdio.h, stdlib.h, stdint.h и т.д.), которые не должны лежать в папке проекта.*/
#include <stdint.h>

int plt_init(void);
void plt_process(void);
void plt_delay(uint32_t delay_ms);

#endif /* SRC_PLATFORM_PLATFORM_H_ */
