#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t d1,d2;


void task1(void *arg){
    while (1)
    {
        printf("from the ethernet\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

    }
    vTaskDelete(d1);
    
}
void task2(void *arg){
    while (1)
    {
        printf("from the serial\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

    }
     vTaskDelete(d2);
}

void app_main(){
    printf("inside the rtos\n");
    xTaskCreate(task1,"task1",1000,NULL,8,&d1);
    xTaskCreate(task2,"task2",1200,NULL,2,&d2);
}