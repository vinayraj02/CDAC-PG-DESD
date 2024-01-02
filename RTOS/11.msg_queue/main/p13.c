#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define core 1

TaskHandle_t d1,d2,d3;
QueueHandle_t q;

void task1(void *){
    char buf[]="hi from task 1\n";
    xQueueSend(q,buf,pdMS_TO_TICKS(2000));
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d1);
}

void task2(void *){
    char buf[]="from task 2\n";
    xQueueSend(q,buf,pdMS_TO_TICKS(2000));
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d2);
}

void task3(void *){
    char buf[100],tuf[100];
    xQueueReceive( q,buf,pdMS_TO_TICKS(2000));
    printf("%s\n",buf);
    xQueueReceive( q,tuf,pdMS_TO_TICKS(2000));
    printf("%s\n",tuf);
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d3);
}

void app_main(){
    printf("from the main\n");
    q = xQueueCreate( 6,100);
    xTaskCreatePinnedToCore(task1,"task1",2048,NULL,8,&d1,core);
    xTaskCreatePinnedToCore(task2,"task2",2048,NULL,7,&d2,core);
    xTaskCreatePinnedToCore(task3,"task3",2048,NULL,6,&d3,core);

}