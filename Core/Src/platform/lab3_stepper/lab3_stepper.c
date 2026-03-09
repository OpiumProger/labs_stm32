/* Директива препроцессора для подключения заголовочного файла */
#include "lab3_stepper.h"

/* Подключение заголовочного файла main.h
 * main.h в свою очередь подключает _hal.h" - файл
 * необходимый для работы с периферией МК stm32 */
#include "main.h"

#define STP1_GPIO_Port	GPIOA
#define STP1_GPIO_Port	GPIOA
#define STP1_GPIO_Port	GPIOA
#define STP1_GPIO_Port	GPIOA

#define STP1_Pin	GPIO_PIN_0
#define STP2_Pin	GPIO_PIN_0
#define STP3_Pin	GPIO_PIN_0
#define STP4_Pin	GPIO_PIN_0

void plt_stepper_full(uint8_t step_n)
{
	switch (step_n) {
		case 0:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
	}

}

void plt_stepper_half(uint8_t step_n)
{

}

void plt_stepper(int dir)
{
	/* */
	static int step_n = 0;
	switch (step_n) {
		case value:

			break;
		default:
			break;
	}

}
