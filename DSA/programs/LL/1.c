#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void insbeg(int ele);
void insend(int ele);
void insbef(int ser, int ele);
void insaft(int ser, int ele);
int delbeg();
int delend();
void delspec(int ele);
void travf();
void travb();
void fun(struct node *cur);


int main()
{
    insbeg(10);
    insbeg(20);
    travf();   
    delspec(20);
    travf();
}

void insbeg(int ele)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // head = temp;
    temp->data = ele;
    temp->next = head;
    head = temp;

}

void insend(int ele)
{
    struct node *cur, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;

    cur = head;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (cur != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void insaft(int ser, int ele)
{
    struct node *cur, *temp;
    cur = head;
    if (head != NULL)
    {
        while (cur != NULL && cur->data != ser)
        {
            cur = cur->next;
        }
        if (cur->data == ser)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = cur->next;
            cur->next = temp;
        }
        else
        {
            printf("element not found\n");
        }
    }
    else
    {
        printf("list is empty\n");
    }
}

void insbef(int ser, int ele)
{
    struct node *cur, *temp;
    cur = head;
    if (head != NULL)
    {
        if (cur->data == ser)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            head = temp;
            temp->data = ele;
            temp->next = NULL;
        }
        else
        {
            while (cur->next != NULL && cur->next->data != ser)
            {
                cur = cur->next;
            }
            if (cur->next->data == ser)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = ele;
                temp->next = cur->next;
                cur->next = temp;
            }
            else
            {
                printf("element not found\n");
            }
        }
    }
    else
    {
        printf("list is empty\n");
    }
}

int delbeg(){
    int x=-389;
    struct node *temp;
    temp=head;
    x=temp->data;
    head=temp->next;
    free(temp);
    return x;
}

int delend(){
    int x;
    struct node *cur,*temp;
    cur=head;
    if(cur!=NULL){
        if(cur->next==NULL){
                temp=head;
                x=temp->data;
                head=temp->next;
                free(temp);
                return x;
        }
        else{
        while(cur->next->next!=NULL){
            cur=cur->next;
        }
        temp=cur->next;
        x=temp->data;
        cur->next=temp->next;
        free(temp);
        return x;
        }
    }
    else{
        printf("list is empty\n");
    }
}

void delspec(int ele){

    struct node *cur,*temp;
    cur=head;
    if(cur!=NULL){
        if(cur->data==ele){
            head=cur->next;
            free(cur);
        }else{
            while(cur->next!=NULL && cur->next->data!=ele){
                cur=cur->next;
            }
            if(cur->next->data==ele){
                temp=cur->next;
                cur->next=temp->next;
                free(temp);
            }
            else{
                printf("element not found\n");
            }
        }
    }
    else{
        printf("list is empty\n");
    }

}

void travf(){
    struct node *cur;
    cur=head;
    while(cur!=NULL){
        printf("%d\n",cur->data);
        cur=cur->next;
    }
}

void travb(){
    if(head!=NULL){
        fun(head);
    }
    else{
        printf("list is empty\n");
    }
}

void fun(struct node *cur){
        if(cur==NULL)
            return;
        fun(cur->next);
        printf("%d\n",cur->data);
}


