#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"

TaskHandle_t d1,d2;
SemaphoreHandle_t b_sem;

void task1(void *){
    xSemaphoreTake(b_sem, pdMS_TO_TICKS(2000));
    printf("adc task is started\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
    printf("data from adc Acquired 1\n");
    xSemaphoreGive(b_sem);
    vTaskDelete(d1);
}

void task2(void *){
    xSemaphoreTake(b_sem, pdMS_TO_TICKS(2000));
    printf("started adc processing\n");
    printf("data from adc Acquired 2\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
    xSemaphoreGive(b_sem);
    vTaskDelete(d2);
}

void app_main(){
    printf("from the main\n");
    b_sem = xSemaphoreCreateBinary();
    xTaskCreatePinnedToCore(task1,"task1",1048,NULL,8,&d1,0);
    xTaskCreatePinnedToCore(task2,"task2",1000,NULL,8,&d2,0);
}
