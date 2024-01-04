#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t d_d1,d_d2;

void task1(void *arg){
    printf("from the task 1\n");
    vTaskDelete(d_d1);
}

void task2(void *arg){
    printf("from the task 2\n");
    vTaskDelete(d_d2);
}


void app_main(){
    BaseType_t th1,th2;
    printf("welcome to the rtos\n");
    th1 = xTaskCreate(task1,"task1",1000,NULL,8,&d_d1);
    th2 = xTaskCreate(task2,"task2",1200,NULL,1,&d_d2);
}