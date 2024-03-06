#include <stdio.h>
int main()
{
    int a[3]={1,1,1};
    int sz = sizeof(a)/sizeof(a[0]);
    int* p = a;
    int* j = a + sz - 1;
    int dis = j - p;
    printf("%d",dis);
    return 0;
}