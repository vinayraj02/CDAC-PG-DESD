#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

TaskHandle_t d1 = NULL;

void task1(void *arg) {
    while (1) {
        // Task actions
        printf("Task is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000 milliseconds
    }
}


void app_main() {
    printf("entered into the main\n");
    xTaskCreatePinnedToCore(task1, "task1", 2048, NULL, 1, &d1,1);

    // Suspend the task initially
    vTaskSuspend(d1);
    
    // Wait for 5 seconds
    vTaskDelay(pdMS_TO_TICKS(5000));

    // Resume the suspended task after 5 seconds
    vTaskResume(d1);
    
    // Main task actions
    while (1) {
        printf("Main is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000 milliseconds
    }
}
