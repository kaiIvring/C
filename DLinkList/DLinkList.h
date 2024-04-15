/* #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
typedef int Elemtype;

typedef struct DLinkNode
{
    Elemtype data;
    struct DLinkNode* next;
    struct DLinkNode* prior;
}DLN;

void InitList(DLN** L);

DLN* CreatNode(Elemtype x);

void PushFront(DLN* L,Elemtype x);

void PushBack(DLN* L,Elemtype x);

void InsertList(DLN* L,int pos,Elemtype x);

Elemtype FindList(DLN* L,int pos);

void DisList(DLN* L);

void DestroyList(DLN** L);

 */