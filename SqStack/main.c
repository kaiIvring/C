#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50
typedef char Elemtype;

typedef struct
{
    Elemtype data[MaxSize];
    int top;
}SqStack;

//顺序栈的基本运算实现

void InitStack(SqStack** S)
{
    (*S) = (SqStack*)malloc(sizeof(SqStack));
    if((*S)==NULL)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    (*S)->top = -1;
}

void DestroyStack(SqStack** S)
{
    free(*S);
    (*S)->top = -1;
}

void StackEmpty(SqStack* S)
{
    if(S->top==-1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

bool Push(SqStack** S,Elemtype x)
{
    if((*S)->top == MaxSize-1)
    {
        return false;
    }
    else
    {
        (*S)->top++;
        (*S)->data[(*S)->top] = x;
        return true;
    }
}

bool Pop(SqStack** S,Elemtype* x)
{
    if((*S)->top == -1)
    {
        return false;
    }
    else
    {
        *x = (*S)->data[(*S)->top];
        (*S)->top--;
        return true;
    }
}

bool GetTop(SqStack* S,Elemtype* x)
{
    if(S->top == -1)
    {
        return false;
    }
    else
    {
        *x = S->data[S->top];
        return true;
    }
}

void DisStack(SqStack* S)
{
    Elemtype temp[MaxSize];
    int i = S->top;
    int p = S->top;
    int j,count = 0;
    while(p != -1)
    {
        temp[i] = S->data[p];
        i--;
        p--;
        count++;
    }
    for(j = 0;j<count-1;j++)
    {
        printf("%c ",temp[j]);
    }
    printf("%c",temp[j]);
    printf("\n");
}

int StackLength(SqStack* S)
{
    int count = 0;
    int p = S->top;
    while(p != -1)
    {
        count++;
        p--;
    }
    return count;
}

void DisPop(SqStack* S)
{
    int p = S->top;
    while(p != 0)
    {
        printf("%c ",S->data[p]);
        p--;
    }
    printf("%c",S->data[p]);
    printf("\n");
}
int main()
{
    int n;
    Elemtype a[MaxSize];
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        getchar();
        scanf("%c",&a[i]);
    }
    SqStack* slist = NULL;
    InitStack(&slist);
    StackEmpty(slist);
    for(int i = 0;i<n;i++)
    {
        Push(&slist,a[i]);
    }
    StackEmpty(slist);
    int len = StackLength(slist);
    printf("%d\n",len);
    DisStack(slist);
    DisPop(slist);
    DestroyStack(&slist);
    StackEmpty(slist);
    return 0;
}