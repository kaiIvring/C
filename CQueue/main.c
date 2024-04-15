#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//basic function of Circular Queue
//所有结点都存储数据，没有不用于存储的结点

#define MaxSize 50

typedef int ElemType;

typedef struct CQueue
{
    ElemType data[MaxSize];
    int front;
    int rear;
}CQ;

void InitQueue(CQ* q)
{
    q->front = q->rear = 0;
}

bool IsEmpty(CQ* q)
{
    return(q->front == q->rear);
}

bool IsFull(CQ* q)
{
    return (q->rear + 1) % MaxSize == q->front;
}

int QueueLen(CQ* q)
{
    return((q->rear - q->front + MaxSize) % MaxSize);
}

bool enQueue(CQ* q,ElemType x)
{
    if(IsFull(q))
    {
        printf("queue is full!\n");
        return false;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}

bool deQueue(CQ* q,ElemType* x)
{
    if(IsEmpty(q))
    {
        printf("queue is empty!\n");
        return false;
    }
    *x = q->data[q->front];
    q->front = (q->front + 1) % MaxSize;
    return true;
}

void DisQueue(CQ* q)
{
    //打印队列时不要改变队头队尾指针
    int i = q->front;
    int len = QueueLen(q);
    for(int j = 0;j < len;j++)
    {
        printf("%d ",q->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
}

int main() {
    CQ queue;
    InitQueue(&queue);

    // 入队测试
    for (int i = 1; i <= 5; ++i) 
    {
        enQueue(&queue, i * 10);
    }

    // 打印队列
    DisQueue(&queue);

    // 出队测试
    ElemType x;
    for (int i = 0; i < 3; ++i) {
        deQueue(&queue, &x);
    }

    // 再次打印队列
    DisQueue(&queue);

    return 0;
}

