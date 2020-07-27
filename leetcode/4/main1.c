#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	const int size = nums1Size + nums2Size;
	int mid1 = size / 2;
	int mid2 = (size - 1) / 2;
	int nums[size];
	int i1 = 0, i2 = 0, i = 0;

	while (i1 < nums1Size || i2 < nums2Size) {
		if (i2 >= nums2Size) {
			while (i1 < nums1Size) {
				nums[i++] = nums1[i1++];
			}
		}
		while (i1 < nums1Size && nums1[i1] < nums2[i2]) {
			nums[i++] = nums1[i1++];
		}
		if (i1 >= nums1Size) {
			while (i2 < nums2Size) {
				nums[i++] = nums2[i2++];
			}
		}
		while (i2 < nums2Size && nums1[i1] >= nums2[i2]) {
			nums[i++] = nums2[i2++];
		}
		if (i > mid1) {
			break;
		}
	}
	return (double)(nums[mid1] + nums[mid2])/2;
}

int main(void)
{
	int nums1[] = {1, 3};
	int nums2[] = {2, 4};

	double ret = findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int),
			nums2, sizeof(nums2)/sizeof(int));
	printf("%lf\n", ret);

	return 0;
}
