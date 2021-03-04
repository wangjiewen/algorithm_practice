#include <bits/stdc++.h>

using namespace std;

void pr_envlopes(vector<vector<int>> &envelopes)
{
	for (auto env : envelopes) {
		cout << env[0] << ", " << env[1] << endl;
	}
}

class Solution {
private:
int LIS(vector<vector<int>> &nums)
{
	vector<int> dp(nums.size(), 1);
	int ret = 0;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i][1] > nums[j][1]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}

	return ret;
}

public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
				return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
		});
		pr_envlopes(envelopes);
		return LIS(envelopes);
	}
};

int main(void)
{
	Solution s;
	//vector<vector<int>> envelopes = {{5,4},{6,7},{6,4},{2,3}};
	//vector<vector<int>> envelopes = {{1,1},{1,1},{1,1},{1,1}};
	vector<vector<int>> envelopes = {{30,50},{12,2},{3,4},{12,15}};
	//vector<vector<int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,360},{7,380}};
	//vector<vector<int>> envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};

	int ret = s.maxEnvelopes(envelopes);
	cout << ret << endl;

	return 0;
}

