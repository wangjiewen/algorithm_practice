#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int> &nums) {
		int n = nums.size();
		for (auto num : nums) {
			int x = (num - 1) % n;
			nums[x] += n;
		}
		vector<int> ret;
		for (int i = 0; i < n; i++) {
			if (nums[i] <= n)
				ret.push_back(i + 1);
		}
		return ret;
	}

};

int main(void)
{
	Solution s;
	vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> ret;

	ret = s.findDisappearedNumbers(nums);
	for (auto num : ret) {
		cout << num << ", ";
	}
	cout << endl;
	return 0;
}

