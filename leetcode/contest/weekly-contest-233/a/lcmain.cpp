#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int ret = 0, temp = 0, prev = 0;
		temp = nums[0];
		prev = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i-1]) {
				temp += nums[i];
			} else {
				ret = max(ret, temp);
				temp = nums[i];
			}
			prev = nums[i];
		}
		ret = max(ret, temp);
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> nums = {10,20,30,5,10,50};

	int ret = s.maxAscendingSum(nums);
	cout << ret << endl;

	return 0;
}

