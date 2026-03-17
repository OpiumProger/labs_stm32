#ifndef SRC_PLATFORM_LAB3_STEPPER_LAB3_STEPPER_H_
#define SRC_PLATFORM_LAB3_STEPPER_LAB3_STEPPER_H_

#include <stdint.h>

void plt_stepper_full(uint8_t step_n);
void plt_stepper_half(uint8_t half_step_n);
void plt_stepper(int dir);
#endif /* SRC_PLATFORM_LAB3_STEPPER_LAB3_STEPPER_H_ */
