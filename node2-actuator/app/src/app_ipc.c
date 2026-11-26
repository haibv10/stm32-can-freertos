#include "app_ipc.h"

#include "app_cfg.h"
#include "app_ui.h"

QueueHandle_t xSensorQueue = NULL;
QueueHandle_t xButtonQueue = NULL;
QueueHandle_t xUiQueue = NULL;

bool app_ipc_init(void) {
    xSensorQueue = xQueueCreate(SENSOR_QUEUE_LENGTH, sizeof(SensorData_t));
    xButtonQueue = xQueueCreate(BUTTON_QUEUE_LENGTH, sizeof(uint8_t));
    xUiQueue = xQueueCreate(UI_QUEUE_LENGTH, sizeof(UiView_t));
    return (xSensorQueue != NULL) && (xButtonQueue != NULL) && (xUiQueue != NULL);
}
