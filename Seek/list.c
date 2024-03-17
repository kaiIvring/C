#include "list.h"

void InitList(SL** L)
{
    *L=(SL*)malloc(sizeof(SL));
    (*L) -> length = 0;
}

void CreatList(SL* L,int n)
{
    int a[2000];
    for(int j = 0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
    int i = 0,k = 0;
    while(i<n)
    {
        L -> data[k] = a[i];
        k++;
        i++;
    }
    L -> length = k;
}

void Reverse(SL* L,int len)
{
    int i = 0;
    int j = len-1;
    while(i<j)
    {
        int temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
        i++;
        j--;
    }
}

void Seek(SL* L,int x,int y,int* f,int* b)
{
    for(int i = 0;i<L->length;i++)
    {
        if(L->data[i]>x&&L->data[i]<y)
        {
            *f = L->data[i-1];
            *b = L->data[i+1];
            break;
        }
    }
}

void DispList(SL* L)
{
    int i;
    for(i = 0;i < L->length-1;i++)
    {
        printf("%d ",L->data[i]);
    }
    if(i == L->length-1)
    {
        printf("%d",L->data[i]);
    }
}

void DestroyList(SL** L)
{
    free(*L);
}
