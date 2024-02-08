#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*top=NULL;

void push(int ele);
int pop();
int peek();
int isempty();
void display();

int main(){
    int c,item;
    while(1){
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display all elements\n");
        printf("5.quit\n");
        printf("enter your choice\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("enter the element to be pushed\n");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item=pop();
                printf("popped item is : %d\n",item);
                break;
            case 3:
                printf("item at the top is : %d\n",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("enter the correct choice\n");

        }
    }

}

void push(int ele){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("stack is overflow\n");
        return;
    }
    else{
        temp->data=ele;
        temp->link=top;
        top=temp;
    }
    
}

int pop(){
    struct node *temp;
    int item;
    if(isempty()){
        printf("stack is underflow\n");
        exit(1);
    }
    else{
        temp=top;
        item=temp->data;
        top=top->link;
        free(temp);
        return item;
    }
}

int peek(){
    if(isempty()){
        printf("stack is underflow\n");
        exit(1);
    }
    else{
        return top->data;
    }
}

int isempty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    struct node *ptr;
    ptr=top;
    if(isempty()){
        printf("stack is empty\n");
        return ;
    }
    else{
        printf("stack elements are:\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}