#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *ret;
	int i, j;

	ret = (int *)malloc(2*sizeof(int));
	*returnSize = 2;

	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (target == nums[i] + nums[j]) {
				ret[0] = i;
				ret[1] = j;
				goto out;
			}
		}
	}

out:
	return ret;	
}

int main(void)
{
	int nums[] = {2, 7, 11, 5};
	int target = 9;
	int *ret, ret_size;

	ret = twoSum(nums, sizeof(nums)/sizeof(int), target, &ret_size);

	for (int i = 0; i < ret_size; i++) {
		printf("%d ", ret[i]);
	}
	printf("\n");

	free(ret);
	
	return 0;
}
