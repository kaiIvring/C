#pragma once
#define MaxSize 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SLDataType;

typedef struct Sqlist
{
    SLDataType data[MaxSize];
    int length;
}SL;

void CreatList(SL** L,SLDataType a[],int n);//由a中的n个元素创建顺序表

void InitList(SL** L);

void DestroyList(SL** L);

bool ListEmpty(SL* L);

int ListLength(SL* L);

void DispList(SL* L);

bool GetSLData(SL* L,int i,SLDataType* e);

int LocateSLData(SL* L,SLDataType e);

bool ListInsert(SL* L,int i,SLDataType e);

bool ListDelete(SL* L,int i,SLDataType* e);//函数会实现把删除元素值赋给e

void Partition(SL* L);

void Swap(int* x,int* y);
