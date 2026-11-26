#ifndef TASK_ACTUATOR_H
#define TASK_ACTUATOR_H

#include <stdint.h>

#include "FreeRTOS.h"

BaseType_t task_actuator_create(void);

void task_actuator_post_buttons(uint8_t events);

#endif
