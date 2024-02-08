#include<stdio.h>
#include<stdlib.h>

struct stack {
    int *a;
    int size;
    int top;
}s;

void push(int ele);
int pop();
int peek();
int isempty();
int isfull();
void display();

int main(){
    
    printf("enter the size of the stack:\n");
    scanf("%d",&s.size);
    // s.a=(struct stack *)malloc(sizeof(s.size));
    s.a = (int*)malloc(s.size * sizeof(int));
    s.top=-1;
    push(1);
    push(2);
    push(3);
    display();
    pop();
    int x= peek();
    printf("peek value is:%d\n",x);
    free(s.a);
}

void push(int ele){
    if(!isfull()){
        s.top++;
        s.a[s.top]=ele;
    }
    else{
        printf("stack is full\n");
    }
}

int pop(){
    int item=-434;
    if(!isempty()){
        item=s.a[s.top];
        s.top--;
    }
    else{
        printf("stack is empty\n");
        return item;
    }
}

int peek(){
    if(!isempty()){
        return s.a[s.top];
    }
    else{
        return 1;
    }
}

int isempty(){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if(s.top==s.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){

    if(!isempty()){
        printf("elements in the stack are:\n");
        for(int i=s.top;i>=0;i--){
            printf("%d\n",s.a[i]);
            printf("\n");
        }
    }
    else{
        printf("stack is empty\n");
    }
}