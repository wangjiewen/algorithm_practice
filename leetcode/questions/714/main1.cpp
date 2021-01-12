#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int ret = 0;
		int buy = prices[0] + fee;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] + fee < buy) {
				buy = prices[i] + fee;
			} else if (prices[i] > buy) {
				ret += prices[i] - buy;
				buy = prices[i];
			}
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> arr = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	int ret;

	ret = s.maxProfit(arr, fee);
	printf("%d\n", ret);
	return 0;
}
