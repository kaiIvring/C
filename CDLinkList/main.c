#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int Elemtype;

typedef struct CDN
{
    Elemtype data;
    struct CDN* next;
    struct CDN* prior;
}CDN;

CDN* InitList()
{
    CDN* L = (CDN*)malloc(sizeof(CDN));
    if(L == NULL)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    L->next = L;
    L->prior = NULL;
    return L;
}

CDN* CreatNode(Elemtype x)
{
    CDN* newnode = (CDN*)malloc(sizeof(CDN));
    if(newnode == NULL)
    {
        printf("内存分配失败！");
        exit(EXIT_FAILURE);
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prior = NULL;
    return newnode;
}

void PushFront(CDN* L,Elemtype x)
{
    CDN* newnode = CreatNode(x);
    newnode->next = L->next;
    newnode->prior = L;
    L->next = newnode;
    if(L->next == L)
    {
        L->prior = newnode;
    }
    else
    {
        L->next->next->prior = newnode;
    }
}

void PushBack(CDN* L,Elemtype x)
{
    CDN* newnode = CreatNode(x);
    if(L->next == L)
    {
        newnode->prior = L;
        newnode->next = L;
        L->next = newnode;
        L->prior = newnode;
    }
    else
    {
        CDN* cur = L->next;
        while (cur->next != L)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->prior = cur;
        newnode->next = L;
        L->prior = newnode;
    }
}

int ListLength(CDN* L)
{
    CDN* cur = L->next;
    int len = 0;
    while(cur != L)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

void InsertList(CDN* L,Elemtype x,int pos)
{
    CDN* newnode = CreatNode(x);
    CDN* cur = L->next;
    int len = ListLength(L);

    if(pos <= 0 || pos > len)
    {
        printf("Invalid Position!\n");
        return;
    }
    if(pos == 1)
    {
        newnode->next = cur;
        newnode->prior = L;
        cur->prior = newnode;
        L->next = newnode;
        return;
    }

    for(int i = 1;i<pos-1;i++)
    {
        cur = cur->next;
    }

    newnode->next = cur->next;
    newnode->prior = cur;
    cur->next->prior = newnode;
    cur->next = newnode;
}

void DelList(CDN* L,Elemtype* x,int pos)
{
    int len = ListLength(L);
    if(pos<=0 || pos > len)
    {
        printf("Invalid Position!\n");
        return;
    }
    CDN* cur = L->next;
    for(int i = 1;i<pos-1;i++)//遍历找到待删除节点的前一个节点
    {
        cur = cur->next;
    }
    CDN* temp = cur->next;
    cur->next = temp->next;
    temp->next->prior = cur;
    *x = temp->data;
    free(temp);
}

void DisList(CDN* L)
{
    CDN* cur = L->next;
    while(cur != L)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void DestroyList(CDN** L)
{
    CDN* cur = (*L)->next;
    while (cur != (*L))
    {
        CDN* next = cur->next;
        free(cur);
        cur = next;
    }
    free(*L);
    *L = NULL;
}

int main()
{
    CDN* list = InitList();
    return 0;
}