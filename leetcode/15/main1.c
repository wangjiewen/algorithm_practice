#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int **ret = NULL;
	int *ret_temp_row = NULL;
	int size = 0;
	int first, second, third, target;

	ret = (int **)malloc(sizeof(int*) * numsSize * numsSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);

	for (first = 0; first < numsSize; ++first) {
		if (first > 0 && nums[first] == nums[first-1]) {
			continue;
		}
		third = numsSize - 1;
		second = first + 1;
		target = -nums[first];

		while (second < third) {
			if (second > first + 1 &&
					nums[second] == nums[second-1]) {
				second += 1;
				continue;
			}
			if (third < numsSize - 1 &&
					nums[third] == nums[third+1]) {
				third -= 1;
				continue;
			}
			if (nums[second] + nums[third] > target) {
				third -= 1;
			} else if (nums[second] + nums[third] < target) {
				second += 1;
			} else {
				ret_temp_row = (int *)malloc(sizeof(int)*3);
				ret_temp_row[0] = nums[first];
				ret_temp_row[1] = nums[second];
				ret_temp_row[2] = nums[third];
				ret[size] = ret_temp_row;
				(*returnColumnSizes)[size] = 3;
				size += 1;
				second += 1;
			}
		}
	}
	*returnSize = size;

	return ret;
}

int main(void)
{
	//int nums[] = {-1, 0, 1, 2, -1, -4};
	int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
	int numsSize = sizeof(nums)/sizeof(int);
	int returnSize;
	int *returnColumnSizes;
	int **ret;

	printf("%d\n", numsSize);
	ret = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

	printf("%d\n", returnSize);
	for (int i = 0; i < returnSize; ++i) {
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", ret[i][j]);
		}
		free(ret[i]);
		printf("\n");
	}

	free(returnColumnSizes);
	free(ret);

	return 0;
}
