#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include "freertos/stream_buffer.h"

#define core 1

TaskHandle_t d1,d2;
StreamBufferHandle_t s;

uint8_t buf1[] = { 0, 1, 2, 3 };
uint8_t buf2[] = { 5, 8, 4, 9 };

void task1(void *){
    xStreamBufferSend( s,buf1,sizeof(buf1)/sizeof(uint8_t),pdMS_TO_TICKS(2000));
    xStreamBufferSend( s,buf2,sizeof(buf2)/sizeof(uint8_t),pdMS_TO_TICKS(2000));
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d1);

}
void task2(void *){
    uint8_t buf[8];
    xStreamBufferReceive(s,buf,sizeof(buf)/sizeof(uint8_t),pdMS_TO_TICKS(10000));
    for(int i=0;i<8;i++){
        printf("%d\n",buf[i]);
    }
    vTaskDelete(d2);
}

void app_main(){
    printf("from the main\n");
    s = xStreamBufferCreate( 200,10);
    xTaskCreatePinnedToCore(task1,"task1",2048,NULL,8,&d1,core);
    xTaskCreatePinnedToCore(task2,"task2",2048,NULL,6,&d1,core);

}