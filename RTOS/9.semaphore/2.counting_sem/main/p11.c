#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"

int c=0; //shared resource

TaskHandle_t d1,d2,d3,d4;
SemaphoreHandle_t sem;

void task1(void *){
    while (1)
    {
        xSemaphoreTake(sem,pdMS_TO_TICKS(1000)); //sem lock 
        c++;
        printf("task 1:%d\n",c);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xSemaphoreGive(sem); //sem unlock
    }
}

void task2(void *){
    while (1)
    {
        xSemaphoreTake(sem,pdMS_TO_TICKS(1000));
        c++;
        printf("task 2:%d\n",c);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xSemaphoreGive(sem);
    }
}

void task3(void *){
    while (1)
    {
        xSemaphoreTake(sem,pdMS_TO_TICKS(1000));
        c++;
        printf("task 3:%d\n",c);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xSemaphoreGive(sem);
    }
}

void task4(void *){
    while (1)
    {   
        xSemaphoreTake(sem,pdMS_TO_TICKS(1000));
        c++;
        printf("task 4:%d\n",c);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xSemaphoreGive(sem);
    }
}

void app_main(){
    printf("in the main\n");
    sem = xSemaphoreCreateCounting(2,0); //initialsing the counting sem
    xTaskCreatePinnedToCore(task1,"task1",2048,NULL,6,&d1,1);
    xTaskCreatePinnedToCore(task2,"task2",2048,NULL,6,&d2,1);
    xTaskCreatePinnedToCore(task3,"task3",2048,NULL,6,&d3,1);
    xTaskCreatePinnedToCore(task4,"task4",2048,NULL,6,&d4,1);
}