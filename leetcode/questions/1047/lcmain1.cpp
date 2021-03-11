#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string removeDuplicates(string S) {
		string ret;

		for (auto c : S) {
			if (!ret.empty() && ret.back() == c) {
				ret.pop_back();
			} else {
				ret.push_back(c);
			}
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	string ret = s.removeDuplicates("abbaca");
	cout << ret << endl;

	return 0;
}

