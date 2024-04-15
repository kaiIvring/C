/* #include "DLinkList.h"

void InitList(DLN** L)
{
    (*L) = (DLN*)malloc(sizeof(DLN));
    if((*L) == NULL)
    {
        printf("memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
}

DLN* CreatNode(Elemtype x)
{
    DLN* newnode = (DLN*)malloc(sizeof(DLN));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prior = NULL;
    return newnode;
}

void PushFront(DLN* L,Elemtype x)
{
    if(L == NULL)
    {
        printf("链表为空。插入失败！\n");
        return;
    }
    DLN* newnode = CreatNode(x);
    if(L->next == NULL)
    {
        newnode->prior = L;
        L->next = newnode;
    }
    else
    {
        L->next->prior = newnode;
        newnode->next = L->next;
        newnode->prior = L;
        L->next = newnode;
    }
}

void PushBack(DLN* L,Elemtype x)
{
    if(L == NULL)
    {
        printf("链表为空，插入失败！\n");
        return;
    }
    DLN* newnode = CreatNode(x);
    if(L->next == NULL)
    {
        L->next = newnode;
        newnode->prior = L;
    }
    else
    {
        DLN* cur = L->next;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->prior = cur;
    }
}

void InsertList(DLN* L,int pos,Elemtype x)
{
    if(pos<=0)
    {
        printf("插入位置不合法，插入失败！\n");
        return;
    }
    DLN* cur = L;
    for(int i = 1;i<pos;i++)
    {
        cur = cur->next;
        if(cur == NULL)
        {
            printf("插入位置不合法，插入失败！\n");
            return;
        }
    }
    DLN* newnode = CreatNode(x);
    if(cur->next == NULL)
    {
        newnode->prior = cur;
        cur->next = newnode;
    }
    else
    {
        newnode->next = cur->next;
        cur->next->prior = newnode;
        newnode->prior = cur;
        cur->next = newnode;
    }
}

Elemtype FindList(DLN* L,int pos)
{
    DLN* cur = L->next;
    for(int i = 1;i<pos;i++)
    {
        cur = cur->next;
    }
    Elemtype x = cur->data;
    return x;
}

void DisList(DLN* L)
{
    if(L==NULL)
    {
        printf("链表为空\n");
        return;
    }
    else
    {
        DLN* cur = L->next;
        while (cur != NULL)
        {
            printf("%d ",cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

void DestroyList(DLN** L)
{
    if((*L) == NULL)
    {
        printf("链表为空，无需销毁！\n");
    }
    DLN* cur = (*L)->next;
    DLN* prev = (*L);
    while(cur != NULL)
    {
        free(prev);
        prev = cur;
        cur = cur->next;
    }
    free(prev);
    prev = NULL;
    cur = NULL;
} */