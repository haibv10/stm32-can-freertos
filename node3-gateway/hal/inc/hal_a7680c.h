#ifndef HAL_A7680C_H
#define HAL_A7680C_H

#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"

#include "stm32f1xx_hal.h"

void hal_a7680c_init(UART_HandleTypeDef *huart);
bool hal_a7680c_send(const char *text);
bool hal_a7680c_read_byte(uint8_t *byte);
void hal_a7680c_irq_handler(void);
void hal_a7680c_set_rx_task(TaskHandle_t task);

#endif
