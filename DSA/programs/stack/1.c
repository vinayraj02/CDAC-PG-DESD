#include<stdio.h>
#include<stdlib.h>

int stack_arr[10];
int top=-1;


void push(int ele);
int pop();
int peek();
int isempty();
int isfull();
void display();

int main(){
     int c,item;
     while (1)
     {
       printf("1.push\n");
       printf("2.pop\n");
       printf("3.display top of the stack\n");
       printf("4.display all the stack elements\n");
       printf("5.quit\n");
       printf("enter your choice:\n");
       scanf("%d",&c);
       switch(c){
        case 1:
            printf("enter the number to be pushed\n");
            scanf("%d\n",&item);
            push(item);
            break;
        case 2:
            item=pop();
            printf("popped number is %d\n",item);
            break;
        case 3:
            printf("the element top of the stack is: %d\n",peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("enter the right choice\n");
            
       }
     }
     
    

}

void push(int ele){
    if(isfull()){
        printf("stack is full\n");
        return;
    }
    else{
        top = top+1;
        stack_arr[top]=ele;
      
    }
}

int pop(){
    int ele;
    if(isempty()){
        printf("stack is empty\n");
        exit(1);
    }
    else{
        ele=stack_arr[top];
        top=top-1;
        return ele;
    }
}

int peek(){
    if(isempty()){
        printf("stack is empty\n");
        exit(1);

    }
    else{
        return stack_arr[top];
    }
}

int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if(top==(10-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    int i;
    if(isempty()){
        printf("stack is empty\n");
        return ;
    }
    else{
        printf("stack elements are:\n");
        for(i=top;i>=0;i--){
            printf("%d\n",stack_arr[i]);
            printf("\n");
        }
    }
}