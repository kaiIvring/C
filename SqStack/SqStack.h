/* #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50
typedef char Elemtype;

typedef struct
{
    Elemtype data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack** S);

void DestroyStack(SqStack** S);

void StackEmpty(SqStack* S);

bool Push(SqStack** S,Elemtype x);

bool Pop(SqStack** S,Elemtype* x);

bool GetTop(SqStack* S,Elemtype* x);

void DisStack(SqStack* S);

int StackLength(SqStack* S);

void DisPop(SqStack* S);








 */