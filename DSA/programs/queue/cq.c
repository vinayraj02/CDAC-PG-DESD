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
    printf("enter the size of the circular queue\n");
    scanf("%d",&q.size);
    q.a=(int *)malloc(q.size * sizeof(int));
    q.front=q.back=-1;
    enque(3);
    enque(4);
    enque(5);
    display();
    deque();
    display();


}

int overflow(){
    if((q.front == 0 && q.back == q.size-1)  || q.front==q.back+1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int underflow(){
    if(q.front== -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int ele){  
    if(underflow())   // condition to check queue is empty  
    {  
        q.front++;  
        q.back++;  
        q.a[q.back]=ele;  
    }  
    else if((overflow())) // condition to check queue is full  
    {  
        printf("Queue is overflow..");  
    }  
    else  
    {  
        q.back=(q.back+1)%q.size;       // rear is incremented  
        q.a[q.back]=ele;     // assigning a value to the queue at the rear position.  
    }  
}  

int deque(){
    int x=-535;
    if(!underflow()){
        x=q.a[q.front];
    }
        if(q.front==q.back){
            q.front=q.back=-1;
        }
        else{
            q.front=(q.front++)%q.size;
        }
    
        printf("queue is empty\n");
    
}

void display(){  
    int i=q.front;  
    if(q.front==-1 && q.back==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :\n");  
       for(i;i<=q.back;i++){
            printf("%d\n",q.a[i]);
            printf("\n");
       }  
    }  
}