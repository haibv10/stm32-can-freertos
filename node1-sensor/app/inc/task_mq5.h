#ifndef TASK_MQ5_H
#define TASK_MQ5_H

#include <stdint.h>

#include "FreeRTOS.h"

BaseType_t task_mq5_create(void);

void task_mq5_request(uint32_t request_id);

#endif
