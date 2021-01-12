#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int solve(int k, vector<int>& prices)
{
	if (prices.empty())
		return 0;
	int buy[1005][505];
	int sell[1005][505];
	int size = prices.size();
	k = min(k, size/2);
	int ret = 0;

	buy[0][0] = -prices[0];
	sell[0][0] = 0;
	for (int i = 1; i <= k; i++) {
		buy[0][i] = sell[0][i] = INT_MIN/2;
	}

	for (int i = 1; i < size; i++) {
		buy[i][0] = max(buy[i-1][0], sell[i-1][0] - prices[i]);
		for (int j = 1; j <= k; j++) {
			buy[i][j] = max(buy[i-1][j], sell[i-1][j] - prices[i]);
			sell[i][j] = max(sell[i-1][j], buy[i-1][j-1] + prices[i]);
			ret = max(ret, sell[i][j]);
		}
	}

	return ret;
}

int main(void)
{
	vector<int> prices = {3,3,5,0,0,3,1,4};
	int k = 2;
	int ret = solve(k, prices);
	cout << ret << endl;
	return 0;
}
