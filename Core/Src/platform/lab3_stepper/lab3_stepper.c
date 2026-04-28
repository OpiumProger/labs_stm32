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
		case 0:  // Такт 1
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 1:  // Такт 2
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 2:  // Такт 3
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 3:  // Такт 4
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 4:  // Такт 5
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_RESET);
			break;
		case 5:  // Такт 6
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
			break;
		case 6:  // Такт 7
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
			break;
		case 7:  // Такт 8
			HAL_GPIO_WritePin(STP1_GPIO_Port, STP1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STP2_GPIO_Port, STP2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP3_GPIO_Port, STP3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(STP4_GPIO_Port, STP4_Pin, GPIO_PIN_SET);
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
 * @brief вращает шаговый двигатель в заданном направлении
 *
 * @param dir - направление вращения, <-1> - против часовой стрелки, <1> - по часовой стрелке
 * <0> - двигатель остановлен
 * @return return
 */
/**
 * @brief вращает шаговый двигатель в заданном направлении
 *
 * @param dir - направление вращения, <-1> - против часовой стрелки, <1> - по часовой стрелке
 * <0> - двигатель остановлен
 * @return void
 */
void plt_stepper(int dir)
{
    int half_step_n = 0;  // текущий номер полу-шага (0-7)

    if (dir == 0) {
        // Двигатель остановлен - ничего не делаем
        return;
    }

    // Изменяем номер полу-шага в зависимости от направления
    half_step_n += dir;

    if (half_step_n >= 8) {
        half_step_n = 0;  // сброс на 0
    } else if (half_step_n < 0) {
        half_step_n = 7;  // перескок на 7
    }

    plt_stepper_half(half_step_n);
    plt_delay(15);
}
