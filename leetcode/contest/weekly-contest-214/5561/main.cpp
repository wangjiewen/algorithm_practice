#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int nums[105];
int max_nums[105];

class Solution {
public:
	int getMaximumGenerated(int n) {
		int local;

		nums[0] = max_nums[0] = 0;
		nums[1] = max_nums[1] = 1;
		for (int i = 1; i <= 50; i++) {
			local = 2 * i;
			nums[local] = nums[i];
			max_nums[local] = max_nums[local - 1];

			local = 2 * i + 1;
			nums[local] = nums[i] + nums[i + 1];
			max_nums[local] = max(nums[local], max_nums[local - 1]);
		}

		return max_nums[n];
	}
};

int main(void)
{
	Solution s;
	int ret;

	ret = s.getMaximumGenerated(15);
	printf("%d\n", ret);
	
	return 0;
}
