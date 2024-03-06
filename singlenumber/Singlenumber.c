#include <stdio.h>
//异或位运算!：相同两数结果为0，0与任意数结果为那个任意数，因为题中明确说明数组中只有两个数字相同，所以可以这样求解
int singleNumber(int* nums, int numsSize) 
{
    int ans = nums[0];
    if (numsSize > 1)
    {
        for (int i = 1; i < numsSize; i++)
        {
            ans = ans ^ nums[i];
        }
    }
    return ans;
}
int main()
{
    int nums[5]={2,1,2,4,4};
    int sz = sizeof(nums)/sizeof(nums[0]);
    int single = singleNumber(nums,sz);
    printf("%d",single);
    return 0;
}