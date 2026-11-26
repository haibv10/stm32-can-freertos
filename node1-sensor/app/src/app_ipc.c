#include "app_ipc.h"

#include "app_cfg.h"

QueueHandle_t xDht11Queue = NULL;
QueueHandle_t xMq5Queue = NULL;

bool app_ipc_init(void) {
    xDht11Queue = xQueueCreate(SENSOR_RESULT_QUEUE_LENGTH, sizeof(Dht11Sample_t));
    xMq5Queue = xQueueCreate(SENSOR_RESULT_QUEUE_LENGTH, sizeof(Mq5Sample_t));
    return (xDht11Queue != NULL) && (xMq5Queue != NULL);
}
