#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int ret = 0, sign = 1, num;
		stack<int> ops;

		ops.push(1);
		int i = 0;
		while (i < s.length()) {
			if (s[i] == '+') {
				sign = ops.top();
				i++;
			} else if (s[i] == '-') {
				sign = -ops.top();
				i++;
			} else if (s[i] == '(') {
				ops.push(sign);
				i++;
			} else if (s[i] == ')') {
				ops.pop();
				i++;
			} else if (s[i] == ' ') {
				i++;
			} else {
				num = 0;
				while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 - '0' + s[i];
					i++;
				}
				ret += sign * num;
			}
		}
		return ret;
	}
};

int main(void)
{
	Solution so;
	//string s = "(1+(4+5+2)-3)+(6+8)";
	string s = "1 + 1";

	int ret = so.calculate(s);
	cout << ret << endl;

	return 0;
}

