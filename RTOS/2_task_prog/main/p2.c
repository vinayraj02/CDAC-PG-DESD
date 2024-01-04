#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t d_d;
void task(void *arg){
    printf("hi from the task\n");
    vTaskDelete(d_d);
}

void app_main(){
    BaseType_t th;
    printf("welcome to the rtos\n");
    th = xTaskCreate(task,"task",2048,NULL,1,&d_d);
}

