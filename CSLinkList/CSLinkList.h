/* #include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int Elemtype;

typedef struct CSN
{
    Elemtype data;
    struct CSN* next;
}CSN;

void InitList(CSN** L);

CSN* CreatNode(Elemtype x);

void PushFront(CSN* L,Elemtype x);

void PushBack(CSN* L,Elemtype x);

void InsertList(CSN* L,Elemtype x,int pos);

void DelList(CSN* L,int pos);

void DisList(CSN* L);

void DestroyList(CSN** L); */