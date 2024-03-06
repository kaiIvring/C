#include <stdio.h>
void moveZeroes(int* nums, int numsSize) 
{
    int j = 0;
    int i = 0;
    while(i<numsSize)
    {
        if(nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }
}
int main()
{
    int nums[3]={0,0,1};
    int sz = sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums,sz);
    for(int i = 0;i < sz;i++)
    {
        printf("%d ",nums[i]);
    }
}