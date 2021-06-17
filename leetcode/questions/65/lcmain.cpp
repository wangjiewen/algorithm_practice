#include <bits/stdc++.h>

using namespace std;

// 根据题目描述，暴力
class Solution {
	private:

		bool isUnsigned(string s, int &loc) {
			if (!isdigit(s[loc]))
				return false;
			for (; loc < s.size(); loc++) {
				if (!isdigit(s[loc]))
					return true;
			}
			return true;
		}

		bool isInt(string s, int &loc) {
			if (s[loc] == '+' || s[loc] == '-')
				loc++;

			return isUnsigned(s, loc);
		}

		bool isDecimal(string s, int &loc) {
			if (s[loc] == '+' || s[loc] == '-')
				loc++;

			if (s[loc] == '.') {
				loc++;
				return isUnsigned(s, loc);
			} else {
				if (!isUnsigned(s, loc))
					return false;
				if (s[loc] != '.')
					return false;
				loc++;
				if (!isdigit(s[loc]))
					return true;
				else
					return isUnsigned(s, loc);
			}
			return false;
		}
	public:
		bool isNumber(string s) {
			int len = s.size();
			int loc = 0;

			if (!isDecimal(s, loc)) {
				loc = 0;
				if (!isInt(s, loc))
					return false;
			}

			if (loc == len)
				return true;
			if (s[loc] == 'e' || s[loc] == 'E') {
				loc++;
				if (isInt(s, loc)) {
					if (loc == len)
						return true;
					return false;
				}
				return false;
			}
			return false;

		}
};

int main(void)
{
	Solution s;

	return 0;
}

