#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/message_buffer.h"

#define core 1

TaskHandle_t d1,d2;
MessageBufferHandle_t msg;

uint8_t msg1[]={0,1,2};
uint8_t msg2[]={3,4,5};

void task1(void *)
{
    printf("from the task1\n");
    xMessageBufferSend( msg,msg1,sizeof(msg1)/sizeof(int),pdMS_TO_TICKS(2000));
    xMessageBufferSend( msg,msg2,sizeof(msg2)/sizeof(int),pdMS_TO_TICKS(2000));
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d1);

}

void task2(void *)
{
    printf("from the task2\n");
    xMessageBufferReceive( msg,msg1,sizeof(msg1)/sizeof(int),pdMS_TO_TICKS(2000));
    for(int i=0;i<3;i++){
        printf("msg1 is :%d\n",msg1[i]);
    }
    xMessageBufferReceive( msg,msg1,sizeof(msg1)/sizeof(int),pdMS_TO_TICKS(2000));
    for(int i=0;i<3;i++){
        printf("msg2 is :%d\n",msg2[i]);
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
    vTaskDelete(d2);
}

void app_main(){
    msg = xMessageBufferCreate( 200 );
    xTaskCreatePinnedToCore(task1,"task1",2048,NULL,8,&d1,core);
    xTaskCreatePinnedToCore(task2,"task2",2048,NULL,7,&d2,core);
}