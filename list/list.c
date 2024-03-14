#include "list.h"

//双重指针L指向main函数传入的指针L1的地址，对L解引用找到L1
//指针L1指向结构体seqlist
//顺序表只是抽象地存在(*L->data,*L->length),没有真正地利用结构体变量创建顺序表
void CreatList(SL** L,SLDataType a[],int n)
{
    //malloc:动态内存分配
    //找到一块内存空间，返回那块内存第一个字节的地址
    //因此，可以将那个地址赋给一个指针变量，并通过该指针来访问那块内存
    *L = (SL*)malloc(sizeof(SL));
    int i = 0,k = 0;
    while(i<n)
    {
        (*L) -> data[k] = a[i];
        k++;
        i++;
    }
    (*L) -> length=k;
}

void InitList(SL** L)
{
    *L=(SL*)malloc(sizeof(SL));
    (*L) -> length = 0;
}

void DestroyList(SL** L)
{
    free(*L);
}

bool ListEmpty(SL* L)
{
    return(L -> length == 0);
}

int ListLength(SL* L)
{
    return(L -> length);
}

void DispList(SL* L)
{
    for(int i = 0;i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

bool GetSLData(SL* L,int i,SLDataType* e)
{
    if(i<1 || i>L->length)
    {
        return false;
    }
    *e = L -> data[i-1];
    return true;
}

int LocateSLData(SL* L,SLDataType e)
{
    int i = 0;
    while(i<L->length && L->data[i] != e);
    {
        i++;
    }
    if(i>=L->length)
    {
        return 0;
    }
    else
    {
        return i+1;
    }
}

bool ListInsert(SL* L,int i,SLDataType e)
{             //i>length+1是为了能够在表末尾插入元素
    if(i<1 || i>L->length + 1 ||L->length==MaxSize)
    {
        return false;
    }
    i--;
    for(int j=L->length;j>i;j--)
    {
        L->data[j] = L->data[j-1];
    }
    L -> data[i] = e;
    L -> length++;
    return true;
}
bool ListDelete(SL* L,int i,SLDataType* e)//函数会实现把删除元素值赋给e
{
    if(i<1 || i>L->length)
    {
        return false;
    }
    i--;
    *e = L->data[i];
    for(int j = i;j<L->length;j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

//函数实现将将小于基准值的数移动到基准值前大于的数移动到基准值后
//基准值：顺序表首元素
/*void Partition(SL* L)
{
    int i = 0,j = L->length-1;
    SLDataType base = L->data[0];
    while(i<j)
    {
        while(i<j&&L->data[j]>base)
        {
            j--;
        }
        while(i<j&&L->data[i]<=base)
        {
            i++;
        }
        if(i<j)
        {
            Swap(&L->data[i],&L->data[j]);
        }
    }
    Swap(&L->data[0],&L->data[i]);

}

void Swap(int* x,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}*/