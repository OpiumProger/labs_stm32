#ifndef SRC_PLATFORM_LAB4_ADC_LAB4_ADC_H_
#define SRC_PLATFORM_LAB4_ADC_LAB4_ADC_H_

#include <stdint.h>

void plt_adc_start(void);
void plt_adc_stop(void);
int plt_adc_conversion_poll(void);
uint32_t plt_adc_get_value(void);
float plt_adc_get_voltage(void);
#endif /* SRC_PLATFORM_LAB4_ADC_LAB4_ADC_H_ */
