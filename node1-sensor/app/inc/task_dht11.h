#ifndef TASK_DHT11_H
#define TASK_DHT11_H

#include <stdint.h>

#include "FreeRTOS.h"

BaseType_t task_dht11_create(void);

void task_dht11_request(uint32_t request_id);

#endif
