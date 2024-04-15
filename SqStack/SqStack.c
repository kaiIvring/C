/* #include "SqStack.h"

void InitStack(SqStack** S)
{
    (*S) = (SqStack*)malloc(sizeof(SqStack));
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
} */