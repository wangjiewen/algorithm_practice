#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int n = customers.size();
		int ret = 0, sat = 0;

		for (int i = 0; i < X; i++) {
			sat += customers[i];
		}
		for (int i = X; i < n; i++) {
			if (!grumpy[i]) {
				sat += customers[i];
			}
		}

		ret = sat;
		for (int i = X; i < n; i++) {
			if (grumpy[i - X])
				sat -= customers[i - X];
			if (grumpy[i])
				sat += customers[i];
			ret = max(ret, sat);
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> customers = {1,0,1,2,1,1,7,5};
	vector<int> grumpy = {0,1,0,1,0,1,0,1};
	int X = 3;

	int ret = s. maxSatisfied(customers, grumpy, X);

	cout << ret << endl;

	return 0;
}

