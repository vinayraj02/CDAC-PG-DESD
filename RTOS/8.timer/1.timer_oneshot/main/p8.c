#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/timers.h"
#include<stdio.h>

TaskHandle_t dd;
TimerHandle_t t1;

void timer_callback(TimerHandle_t timer){
    printf("callback from the timer create\n");
}

void task (void *){
    t1= xTimerCreate("timer",pdMS_TO_TICKS(1000),pdFALSE,0,timer_callback);
    xTimerStart(t1,0);
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(dd);
}


void app_main(){
    printf("entred into the main\n");
    xTaskCreate(task,"task",2048,NULL,6,&dd);
}