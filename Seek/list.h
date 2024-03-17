#pragma once
#define MaxSize 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char SLDataType;

typedef struct Sqlist
{
    SLDataType data[MaxSize];
    int length;
}SL;

void InitList(SL** L);

void CreatList(SL* L,int n);//由a中的n个元素创建顺序表

void DispList(SL* L);

void Reverse(SL* L,int len);

void Seek(SL* L,int x,int y,int* f,int* b);

void DestroyList(SL** L);


