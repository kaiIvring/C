#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[5]={1,2,3,4,5};
    int sz = sizeof(nums)/sizeof(nums[0]);
    int t = 7;
    int rs = 0;
    int* p = twoSum(nums,sz,t,&rs);
    for(int i = 0;i < rs;i++)
    {
        printf("%d ",nums[*p]);
        p++;
    }
    return 0;
}