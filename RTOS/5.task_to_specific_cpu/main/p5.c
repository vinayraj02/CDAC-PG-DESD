#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t d1,d2;

void task1(void *){
    while (1)
    {
        printf("task from the core 1\n");
    }
    vTaskDelete(d1);
    
}
void task2(void *){
    while (1)
    {
        printf("task from the core 2\n");
    }
    vTaskDelete(d2);
}

void app_main(){
    printf("in the rtos program\n");
     // Create Task for Core 1
    xTaskCreatePinnedToCore(task1,"task1",1000,NULL,8,&d1,1);
     // Create Task for Core 0
    xTaskCreatePinnedToCore(task2,"task2",1000,NULL,1,&d2,0);
}