#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50

//basic function of SequenceQueue /kjuː/

typedef int ElemType;

typedef struct SqQueue
{
    ElemType data[MaxSize];
    int front;
    int rear;
}SQ;

void InitQueue(SQ* q)
{
    q->front = 0;
    q->rear = 0;
}

bool IsEmpty(SQ* q)
{
    return (q->front == q->rear);
}

bool enQueue(SQ* q,ElemType x)
{
    if(q->rear==MaxSize)
    {
        printf("queue is full!\n");
        return false;
    }
    q->data[q->rear++] = x;
    return true;
}

bool deQueue(SQ* q,ElemType* x)
{
    if(IsEmpty(q))
    {
        printf("Queue is empty!\n");
        return false;
    }
    *x = q->data[q->front++];
    return true;
}

void GetFront(SQ* q,ElemType* x)
{
    if(IsEmpty(q))
    {
        printf("queue is empty!\n");
        return;
    }
    *x = q->data[q->front];
}

void DisQueue(SQ* q)
{
    if(IsEmpty(q))
    {
        printf("queue is empty!\n");
        return;
    }
    for(int i = q->front;i <= q->rear;i++)
    {
        printf("%d ",q->data[i]);
    }
    printf("\n");
}

int main()
{
    SQ queue;
    InitQueue(&queue);
    return 0;
}
