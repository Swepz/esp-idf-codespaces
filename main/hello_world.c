#include <stdio.h>

#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void hello_task(void *pvParameter) {
  printf("Hello world!\n");
  for (int i = 3; i >= 0; i--) {
    printf("Restarting in %d seconds...\n", i);
    vTaskDelay(1000 / portTICK_RATE_MS);
  }
  printf("Restarting now.\n");
  fflush(stdout);
  esp_restart();
}

void app_main() { xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL); }