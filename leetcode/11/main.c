#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int* height, int heightSize){
	int max_area = 0;
	int temp_area;
	int left = 0, right = heightSize - 1;

	while (left < right) {
		temp_area = MIN(height[left], height[right]) * (right - left);
		max_area = MAX(max_area, temp_area);
		if (height[left] < height[right])
			left++;
		else 
			right--;
	}

	return max_area;
}

int main(void)
{
	int height[] = {1,8,6,2,5,4,8,3,7};
	int ret;

	ret = maxArea(height, sizeof(height)/sizeof(int));
	printf("%d\n", ret);

	return 0;
}
