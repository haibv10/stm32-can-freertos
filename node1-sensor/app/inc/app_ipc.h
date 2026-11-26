#ifndef APP_IPC_H
#define APP_IPC_H

#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"

typedef struct {
    uint32_t request_id;
    uint8_t temperature_c;
    uint8_t humidity_pct;
    bool valid;
} Dht11Sample_t;

typedef struct {
    uint32_t request_id;
    uint16_t gas_raw;
    bool valid;
} Mq5Sample_t;

extern QueueHandle_t xDht11Queue;
extern QueueHandle_t xMq5Queue;

bool app_ipc_init(void);

#endif
