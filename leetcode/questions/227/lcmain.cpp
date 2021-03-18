#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		list<char> ops;
		list<int> nums;

		ops.push_back('+');
		nums.push_back(0);
		int i = 0;
		while (i < s.size()) {
			if (s[i] == ' ') {
				i++;
			} else if (s[i] >= '0' && s[i] <= '9') {
				int num = 0;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 - '0' + s[i];
					i++;
				}

				int ans;
				if (ops.back() == '+' || ops.back() == '-') {
					nums.push_back(num);
				} else if (ops.back() == '*') {
					ans = nums.back() * num;
					nums.pop_back();
					ops.pop_back();
					nums.push_back(ans);
				} else if (ops.back() == '/') {
					ans = nums.back() / num;
					nums.pop_back();
					ops.pop_back();
					nums.push_back(ans);
				}
			} else {
				ops.push_back(s[i]);
				i++;
			}
		}

		int ans = nums.front();
		nums.pop_front();
		while (!ops.empty()) {
			if (ops.front() == '+') {
				ans += nums.front();
			} else {
				ans -= nums.front();
			}
			nums.pop_front();
			ops.pop_front();
		}

		return ans;
	}
};

int main(void)
{
	Solution s;
	//string str = "3+2*2";
	//string str = " 3/2 ";
	string str = " 3+5 / 2 ";

	int ret = s.calculate(str);
	cout << ret << endl;

	return 0;
}

