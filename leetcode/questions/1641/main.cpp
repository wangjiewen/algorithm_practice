#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution {
public:
	int countVowelStrings(int n) {
		int dp[55][5] = {0};
		int ret = 0;

		for (int i = 0; i < 5; i++) {
			dp[0][i] = 1;
		}

		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i-1][0];
			for (int j = 1; j < 5; j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}

		for (int i = 0; i < 5; i++) {
			ret += dp[n-1][i];
		}
		return ret;
	}
};

int main(void)
{
	Solution s;

	int ret = s.countVowelStrings(33);
	cout << ret << endl;
	return 0;
}
