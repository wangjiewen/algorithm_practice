#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		vector<int> nums;
		int num, ans;
		char sign = '+';

		int i = 0;
		while (i < s.size()) {
			if (isdigit(s[i])) {
				num = 0;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 - '0' + s[i];
					i++;
				}

				if (sign == '+') {
					nums.push_back(num);
				} else if (sign == '-') {
					nums.push_back(-num);
				} else if (sign == '*') {
					ans = nums.back() * num;
					nums.pop_back();
					nums.push_back(ans);
				} else if (sign == '/') {
					ans = nums.back() / num;
					nums.pop_back();
					nums.push_back(ans);
				} else {
					cout << "err sign=" << sign << endl;
				}
			} else if (s[i] == ' ') {
				i++;
			} else {
				sign = s[i];
				i++;
			}
		}

		return accumulate(nums.begin(), nums.end(), 0);
	}
};

int main(void)
{
	Solution s;
	string str = "3+2*2";
	//string str = " 3/2 ";
	//string str = " 3+5 / 2 ";

	int ret = s.calculate(str);
	cout << ret << endl;

	return 0;
}

