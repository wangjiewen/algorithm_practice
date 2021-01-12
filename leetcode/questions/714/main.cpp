#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
private:
	int dp[50005] = {0};

public:
	int maxProfit(vector<int>& prices, int fee) {
		int temp_profit;
		int len = prices.size();

		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				temp_profit = max(prices[i] - prices[j] - fee + dp[j], dp[j]);
				dp[i] = max(dp[i], temp_profit);
			}
		}
		return dp[len - 1];
	}
};

int main(void)
{
	Solution s;
	vector<int> arr = {1, 3, 2, 4};
	int fee = 2;
	int ret;

	ret = s.maxProfit(arr, fee);
	printf("%d\n", ret);
	return 0;
}
