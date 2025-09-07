#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2

void blink_task(void *pvParameters) {
  while (true) {
    // printf("LED ON\n");
    gpio_set_level(GPIO_NUM_2, 1);
    vTaskDelay(pdMS_TO_TICKS(250));

    // printf("LED OFF\n");
    gpio_set_level(GPIO_NUM_2, 0);
    vTaskDelay(pdMS_TO_TICKS(250));

  }
}

void print_task(void *pvParameters) {
  while (true) {
    // 2 blinks per second -> 120 beats per minute
    printf("Heart Rate: 120bpm, time=%lu ms\n", (unsigned long)(xTaskGetTickCount()*portTICK_PERIOD_MS)); 
    vTaskDelay(pdMS_TO_TICKS(10000));
  }
}

void app_main() {
  // Initialize GPIO pins
  gpio_reset_pin(LED_PIN);
  gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

  xTaskCreate(blink_task, "BlinkTask", 2048, NULL, 1, NULL);
  xTaskCreate(print_task, "PrintTask", 2048, NULL, 1, NULL);

  while (true) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
