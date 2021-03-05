#include <bits/stdc++.h>

using namespace std;

/*
 * O(nlogn)
 * dp[i]: 长度为 i 的最长上升子序列，末尾数（最大数）是几
 * 如果新数比末尾数大，那么接在后面
 * 如果新数<=末尾数，那么通过二分（logn）找到第一个 >= 该数的数，替换
 * 因为我们希望同等长度的数列，末尾越小，那么可以接的才越长
 */
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

