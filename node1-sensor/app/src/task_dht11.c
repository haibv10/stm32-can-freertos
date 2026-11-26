#include "task_dht11.h"

#include "task.h"

#include "app_cfg.h"
#include "app_ipc.h"
#include "hal_dht11.h"

static TaskHandle_t xDht11TaskHandle = NULL;

static void prvDht11Task(void *pvParameters) {
    (void)pvParameters;

    Dht11Reading_t reading = {0};

    for (;;) {
        uint32_t request_id;
        if (xTaskNotifyWait(0U, 0U, &request_id, pdMS_TO_TICKS(SENSOR_REQUEST_WAIT_MS)) != pdTRUE) {
            continue;
        }
        bool valid = hal_dht11_read(&reading);
        Dht11Sample_t sample = {
            .request_id = request_id,
            .temperature_c = reading.temperature_c,
            .humidity_pct = reading.humidity_pct,
            .valid = valid,
        };
        (void)xQueueSend(xDht11Queue, &sample, pdMS_TO_TICKS(SENSOR_RESULT_TIMEOUT_MS));
    }
}

BaseType_t task_dht11_create(void) {
    return xTaskCreate(prvDht11Task, "DHT11", TASK_DHT11_STACK_WORDS, NULL, TASK_DHT11_PRIO,
                       &xDht11TaskHandle);
}

void task_dht11_request(uint32_t request_id) {
    (void)xTaskNotify(xDht11TaskHandle, request_id, eSetValueWithOverwrite);
}
