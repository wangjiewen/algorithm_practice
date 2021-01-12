#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp[1005];
		int n = cost.size();

		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i <= n; i++) {
			dp[i] = min(dp[i-1] + cost[i-1], dp[i-2]+cost[i-2]);
		}
		return dp[n];
	}
};

int main(void)
{
	Solution s;
	//vector<int> c={10, 15, 20};
	vector<int> c={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

	int ret = s.minCostClimbingStairs(c);
	cout << ret << endl;
	return 0;
}
