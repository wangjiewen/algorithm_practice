#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp = {nums[0]};

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > dp.back()) {
				dp.push_back(nums[i]);
			} else {
				auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
				*it = nums[i];
			}
		}

		return dp.size();
	}

};

int main(void)
{
	Solution s;
	//vector<int> nums = {10,9,2,5,3,7,101,18};
	vector<int> nums = {0,1,0,3,2,3};

	int ret = s.lengthOfLIS(nums);
	cout << ret << endl;
	return 0;
}

