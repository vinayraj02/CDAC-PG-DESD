#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *a;
    int size;
    int front;
    int back;
}q;

void enque(int ele);
int deque();
int overflow();
int underflow();
void display();

int main(){
    printf("enter the size of the queue\n");
    scanf("%d",&q.size);
    q.a=(int *)malloc(q.size * sizeof(int));
    q.front=-1;
    q.back=-1;
    enque(2);
    enque(4);
    enque(5);
    display();
    deque();
    display();
}

int overflow(){
    if(q.back==q.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int underflow(){
    if(q.back == -1 && q.front== -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int ele){
    if(!overflow()){
            if(underflow()){
                q.front++;
            }
                q.back++;
                q.a[q.back]=ele;
        
    }
    else{
            printf("queue is full\n");
        }
}

int deque(){
    int x=-9;
        if(!underflow()){
            x=q.a[q.front];
                    if(q.front==q.back){
                        q.front=q.back=-1;
                    }
                    else{
                        q.front++;
                    }
        }
        else{
            printf("queue is empty\n");
            return x;
        }
}

void display(){
    if(!underflow()){
        int i;
        printf("elements in the queue are:\n");
        for(i=q.front;i<=q.back;i++){
            printf("%d\n",q.a[i]);
            printf("\n");
        }
    }
    else{
        printf("queue is empty\n");
    }
}