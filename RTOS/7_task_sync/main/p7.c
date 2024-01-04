#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t d1,d2,d3;

void t1(void *arg){
    printf("from task 1\n");
    vTaskResume(d2);
    vTaskSuspend(d1);
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void t2(void *arg){
    printf("from task 2\n");
    vTaskResume(d3);
    vTaskSuspend(d2);
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void t3(void *arg){
    printf("from task 3\n");
    vTaskResume(d1);
    vTaskSuspend(d3);
    vTaskDelay(pdMS_TO_TICKS(1000));
}

void app_main(){
    printf("entered into the main\n");
    xTaskCreatePinnedToCore(t1,"task1",2048,NULL,1,&d1,1);
    xTaskCreatePinnedToCore(t2,"task2",2048,NULL,1,&d2,1);
    xTaskCreatePinnedToCore(t3,"task3",2048,NULL,1,&d3,1);
    printf("tasks created successfully\n");
}