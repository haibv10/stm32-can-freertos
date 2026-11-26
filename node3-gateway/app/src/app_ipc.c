#include "app_ipc.h"

#include "app_cfg.h"

QueueHandle_t xSensorQueue = NULL;
QueueHandle_t xThresholdQueue = NULL;
QueueHandle_t xAlarmQueue = NULL;
QueueHandle_t xAtCmdQueue = NULL;
QueueHandle_t xModemEventQueue = NULL;

bool app_ipc_init(void) {
    xSensorQueue = xQueueCreate(SENSOR_QUEUE_LENGTH, sizeof(SensorData_t));
    xThresholdQueue = xQueueCreate(THRESHOLD_QUEUE_LENGTH, sizeof(AlertThresholds_t));
    xAlarmQueue = xQueueCreate(ALARM_QUEUE_LENGTH, sizeof(AlarmState_t));
    xAtCmdQueue = xQueueCreate(AT_CMD_QUEUE_LENGTH, sizeof(AtCommand_t));
    xModemEventQueue = xQueueCreate(MODEM_EVENT_QUEUE_LENGTH, sizeof(ModemEvent_t));
    return (xSensorQueue != NULL) && (xThresholdQueue != NULL) && (xAlarmQueue != NULL) &&
           (xAtCmdQueue != NULL) && (xModemEventQueue != NULL);
}
