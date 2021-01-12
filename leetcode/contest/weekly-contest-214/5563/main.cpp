#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MOD_NUM 1000000007

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
		inventory.push_back(0);
		sort(inventory.begin(), inventory.end(), greater<int>());
		int high = inventory[0], low;
		int ret = 0;

		for (int i = 0; inventory[i] != 0; i++) {
			low = inventory[i];
			int diff = high - low;
			if (diff == 0)	continue;
			int nums = diff * (i + 1);

			if (orders > nums) {
				long long temp;
				temp = diff * (high + low) / 2 * (i + 1);
				temp %= MOD_NUM;
				ret = ret + temp;
				ret %= MOD_NUM;
				high = low;
				orders -= nums;
			} else {
				int t_diff = order / (i + 1);
				long long temp = t_diff * (2 * high + t_diff) / 2 * (i + 1);
				temp %= MOD_NUM;
				ret = ret + temp;
				ret %= MOD_NUM;
				orders -= t_diff * (i + 1);
				high -= t_diff;

				temp = high * orders;
				temp %= MOD_NUM;
				ret = ret + temp;
				ret %= MOD_NUM;
				orders = 0;
				break;
			}
		}
		return ret;
    }
};

int main(void)
{
	Solution s;

	s.
	return 0;
}
