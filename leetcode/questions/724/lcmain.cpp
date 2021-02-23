#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int left = 0, right = 0;

		for (int i : nums) {
			right += i;
		}

		for (int i = 0; i < nums.size(); i++) {
			right -= nums[i];
			if (left == right) {
				return i;
			}
			left += nums[i];
		}
		return -1;
	}
};

int main(void)
{
	Solution s;
	//vector<int> nums = {1, 7, 3, 6, 5, 6};
	vector<int> nums = {1, 2, 3};

	int ret = s.pivotIndex(nums);
	cout << ret << endl;

	return 0;
}

