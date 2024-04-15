/* #include "CSLinkList.h"

void InitList(CSN** L)
{
    (*L) = (CSN*)malloc(sizeof(CSN));
    if((*L)==NULL)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    (*L)->next = (*L);
}

CSN* CreatNode(Elemtype x)
{
    CSN* newnode = (CSN*)malloc(sizeof(CSN));
    if(newnode==NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void PushFront(CSN* L,Elemtype x)
{
    CSN* newnode = CreatNode(x);
    newnode->next = L->next;
    L->next = newnode;
}

void PushBack(CSN* L,Elemtype x)
{
    CSN* newnode = CreatNode(x);
    newnode->next = L;
    if(L->next == L)
    {
        L->next = newnode;
    }
    else
    {
        CSN* cur = L;
        while(cur->next != L)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}

void InsertList(CSN* L,Elemtype x,int pos)
{
    CSN* newnode = CreatNode(x);
    CSN* cur = L;
    if(L->next == L && pos > 1)
    {
        printf("插入位置无效，插入失败！\n");
        return;
    }
    if(pos<=0)
    {
        printf("插入位置无效，插入失败！\n");
        return;
    }
    for(int i = 1;i<pos;i++)
    {
        cur = cur->next;
        if(cur->next == NULL)
        {
            printf("插入位置无效,插入失败！\n");
            free(newnode);
            return;
        }
    }
    if(cur->next = L)
    {
        newnode->next = L;
        cur->next = newnode;
    }
    else
    {
        newnode->next = cur->next;
        cur->next = newnode;
    }
}

void DelList(CSN* L,int pos)
{
    if(pos <= 0)
    {
        printf("删除位置无效，删除失败！\n");
        return;
    }
    CSN* cur = L;
    for(int i = 1;i<pos;i++)
    {
        cur = cur->next;
        if(cur->next == L)
        {
            printf("删除位置无效，删除失败！\n");
            return;
        }
    }
    CSN* del = cur->next;
    cur->next = del->next;
    free(del);
}

void DisList(CSN* L)
{
    CSN* cur = L->next;
    if(cur == L)
    {
        printf("链表为空！\n");
        return;
    }
    while(cur != L)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void DestroyList(CSN** L)
{
    if((*L)->next == (*L))
    {
        printf("链表为空，无需销毁！\n");
        free((*L));
        return;
    }
    CSN* cur = (*L)->next;
    CSN* prev = (*L);
    while (cur != *L)
    {
        free(prev);
        prev = cur;
        cur = cur->next;
    }
    free(prev);
    *L = NULL;
} */