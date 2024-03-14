#include "list.h"
int main()
{
    SL* L1;
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    CreatList(&L1,a,n);
    DispList(L1);
    return 0;
}