#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxValue(int n, int index, int maxSum) {
		int left = index;
		int right = n - index - 1;
		int x = maxSum % n;
		int del1 = min(left, right), del2 = abs(left - right);
		int ret = maxSum / n;

		if (x == 0 && ret >= 1) {
			ret -= 1;
			x = n;
		}
		int add1 = sqrt(x);
		if (add1 <= del1) {
			return ret+add1;
		}
		add1 = min(add1, del1);
		x -= add1 * add1;
		ret += add1;

		int add2 = (int)((double)sqrt(2*x+0.25) - 0.5);
		add2 = min(add2, del2);
		ret += add2;

		return ret;
	}

};

int main(void)
{
	Solution s;
	int ret = s.maxValue(4, 2, 6);
	//int ret = s.maxValue(6,1,10);
	//int ret = s.maxValue(3,2,18);
	cout << ret << endl;

	return 0;
}

