#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if((x & 1)== 0)//记得用括号
    {
        printf("偶数");
    }
    else if((x & 1) == 1)
    {
        printf("奇数");
    }

    return 0;
}