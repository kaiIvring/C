#include <stdio.h>
int maxArea(int* height, int heightSize)
{
    //双指针，每次移动短的一端
    int left = 0;
    int right = heightSize - 1;
    int ans,ans1;
    ans = (right - left) * Min(height[left],height[right]);
    while(left < right)
    {
        ans1 = (right - left) * Min(height[left],height[right]);
        if(ans1 > ans)
        {
            ans = ans1;
        }
        if(height[right] <= height[left])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return ans;
}
int Min(int x,int y)
{
    return x > y ? y : x;
}
int main()
{
    int nums[9]={1,8,6,2,5,4,8,3,7};
    int sz = sizeof(nums)/sizeof(nums[0]);
    int m = maxArea(nums,sz);
    printf("%d",m);
}