#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 50

typedef int Elemtype;

typedef struct LinkNode
{
    Elemtype data;
    struct LinkNode* next;
}SLN;

void InitList (SLN** L)
{
    *L = (SLN*)malloc(sizeof(SLN));
    if (*L == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    (*L)->next = NULL;
}

SLN* CreatNode(Elemtype x)
{
    SLN* newnode = (SLN*)malloc(sizeof(SLN));
    if(newnode==NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void PushFront(SLN* L,Elemtype x)
{
    SLN* newnode = CreatNode(x);
    newnode->next = L->next;
    L->next = newnode;
}
//important!
//✔
/* void PushFront(SLN* L,Elemtype x)
{
    SLN* newnode = CreatNode(x);
    SLN* cur = L;
    newnode->next = cur->next;
    cur->next = newnode;
} */

//cur是一个结构体指针“SLN* cur = L->next”表示它指向L的第一个数据节点
//如果直接把newnode赋给它就变成赋给cur的结构体里的数据,没有对L进行更新
//用cur->next表示它是指向L中的某个结点,改变的是L里的数据
//这也是为什么尾插的时候要用一个prev指针指向最后一个数据节点

//❌
/* void PushFront(SLN* L,Elemtype x)
{
    SLN* newnode = CreatNode(x);
    SLN* cur = L->next;
    newnode->next = cur;
    cur = newnode;
} */


void PushBack(SLN* L, Elemtype x)
{
    SLN* newnode = CreatNode(x);
    SLN* cur = L->next;
    SLN* prev = L;
    while (cur != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = newnode;
}


void DisList(SLN* L)
{
    SLN* cur = L->next;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void InsertList(SLN* L,int pos,Elemtype x)
{
    if(L->next == NULL && pos > 1)
    {
        printf("插入位置无效，插入失败！\n");
        return;
    }
    if(pos<=0)
    {
        printf("插入位置无效，插入失败！\n");
        return;
    }
    SLN* newnode = CreatNode(x);
    SLN* cur = L;
    for(int i = 1;i<pos;i++)
    {
        if(cur==NULL)
        {
            printf("插入位置超出链表长度,插入失败！\n");
            return;
        }
        cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;
}

void DelList(SLN* L,int pos)
{
    if(L == NULL)
    {
        printf("链表为空，删除失败！\n");
        return;
    }
    if(pos<=0)
    {
        printf("删除位置无效，删除失败！\n");
        return;
    }
    SLN* cur = L;
    for(int i = 1;i<pos;i++)
    {
        if(cur == NULL || cur->next == NULL)
        {
            printf("删除位置超出链表长度，删除失败！\n");
        }
        cur = cur->next;
    }
    SLN* del = cur->next;
    cur->next = del->next;
    free(del);
    del = NULL;
}

void DestroyList(SLN** L)
{
    SLN* cur = (*L);
    SLN* next;
    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        //指针被释放后被指针赋值，即指向那个指针指向的位置
        cur = next;
    }
    cur = NULL;
    next = NULL;
}

int main()
{
    SLN* list = NULL;
    InitList(&list);
    InsertList(list,2,2);
    DisList(list);
    DestroyList(&list);
    return 0;
}