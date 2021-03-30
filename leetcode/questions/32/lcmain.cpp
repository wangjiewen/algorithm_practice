#include <bits/stdc++.h>

using namespace std;

/* 以 i 为结尾的有效括号子串长度 */
class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		if (n == 0)
			return 0;
		vector<int> dp(n, 0);
		int ret = 0;

		for (int i = 1; i < n; i++) {
			if (s[i] == ')' && s[i - 1] == '(') {
				dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
			} else if(s[i] == ')' && s[i - 1] == ')') {
				if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			}
			ret = max(ret, dp[i]);
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	int ret = s.longestValidParentheses(")()()(");

	cout << ret << endl;

	return 0;
}

