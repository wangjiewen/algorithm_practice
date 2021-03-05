#include <bits/stdc++.h>

using namespace std;

/*
 * O(n^2)
 * dp[i]: 一定包括第 i 个数的前 i 个数，最长上升子序列有多长
 * dp[i] = max(dp[i], dp[j]+1) 0 <= j < i && nums[j] < nums[i]
 */
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int ret = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			ret = max(ret, dp[i]);
		}

		return ret;
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

