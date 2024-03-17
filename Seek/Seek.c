#include "list.h"
//!!!attention!!!
//用scanf创建数组后传入CreatList函数会导致数组除首元素外其他元素全为0，逆天啊卧槽，我服了
//所以，直接把数组的创建放CreatList里面去吧，我服了
int main()
{
    SL* L;
    InitList(&L);
    int c;
    scanf("%d",&c);
    for(int i = 0;i<c;i++)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        int front = 0;
        int back = 0;
        CreatList(L,n);
        Reverse(L,n);
        Seek(L,x,y,&front,&back);
        printf("%d %d",front,back);
        DestroyList(&L);
    }
    return 0;
}