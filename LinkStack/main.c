#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 50

//the basic function of LinkStack

typedef int Elemtype;

typedef struct Lnode
{
    Elemtype data;
    struct Lnode* next;
}LSN;

LSN* InitStack()
{
    LSN* newnode = (LSN*)malloc(sizeof(LSN));
    if(newnode == NULL)
    {
        printf("malloc fali!\n");
        exit(EXIT_FAILURE);
    }
    newnode->next = NULL;
    return newnode;
}

bool IsEmpty(LSN* top)
{
    return(top == NULL);
}

LSN* CreatNode(Elemtype x)
{
    LSN* newnode = (LSN*)malloc(sizeof(LSN));
    if(newnode == NULL)
    {
        printf("malloc fail\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void Push(LSN* top,Elemtype x)
{
    LSN* newnode = CreatNode(x);
    newnode->next = top->next;
    top->next = newnode;
}

void Pop(LSN* top,Elemtype* x)
{
    if(IsEmpty(top))
    {
        printf("stack id empty!\n");
        exit(EXIT_FAILURE);
    }
    LSN* temp = top->next;
    *x = temp->data;
    top->next = temp->next;
    free(temp);
}

void GetTop(LSN* top,Elemtype* x)
{
    if(IsEmpty(top))
    {
        printf("Stack is empty!");
        exit(EXIT_FAILURE);
    }
    *x = top->next->data;
}

void DestroyStack(LSN** top)
{
    LSN* cur = *top;
    while(cur != NULL)
    {
        LSN* next = cur->next;
        free(cur);
        cur = next;
    }
    *top = NULL;
}


int main()
{
    LSN* top = InitStack();
    return 0;
}