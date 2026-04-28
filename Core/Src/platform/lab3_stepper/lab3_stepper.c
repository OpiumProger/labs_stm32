/* Директива препроцессора для подключения заголовочного файла */
#include "lab3_stepper.h"

/* Подключение заголовочного файла main.h
 * main.h в свою очередь подключает _hal.h" - файл
 * необходимый для работы с периферией МК stm32 */
#include "main.h"

#define STP1_GPIO_Port	SM1_GPIO_Port
#define STP2_GPIO_Port	SM2_GPIO_Port
#define STP3_GPIO_Port	SM3_GPIO_Port
#define STP4_GPIO_Port	SM4_GPIO_Port

#define STP1_Pin	SM1_Pin
#define STP2_Pin	SM2_Pin
#define STP3_Pin	SM3_Pin
#define STP4_Pin	SM4_Pin

/**
 * @brief выполняет переключение обмоток в рамках одного шага ШД
 *
 * @param step_n - номер шага
 * @return void
 */
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


/**
 * @brief выполняет переключение обмоток в рамках одного полу-шага ШД
 *
 * @param half_step_n - номер полу-шага
 * @return return
 */
void plt_stepper_half(uint8_t half_step_n)
{
	switch (half_step_n) {
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
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
	            break;
	        case 2:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
	            break;
	        case 3:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
	            break;
	        case 4:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
	            break;
	        case 5:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
	            break;
	        case 6:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
	            break;
	        case 7:
	            HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
	            break;
	        case 8:
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

/**
 * @brief выполняет переключение обмоток в рамках одного полу-шага ШД
 *
 * @param half_step_n - номер полу-шага
 * @return return
 */

void plt_stepper(int dir)
{
    static int step_n = 0;
    static int step_mode = 0;
    static int max_step = 4;

    if (step_mode == 0) {
        max_step = 4;
    } else {
        max_step = 8;
    }

    if (dir > 0) {
        step_n++;
        if (step_n >= max_step) {
            step_n = 0;
        }
    } else if (dir < 0) {
        step_n--;
        if (step_n < 0) {
            step_n = max_step - 1;
        }
    }

    if (step_mode == 0) {
        plt_stepper_full(step_n);
    } else {
        plt_stepper_half(step_n);
    }
}
