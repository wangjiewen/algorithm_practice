#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string removeDuplicates(string S) {
		string ret;
		stack<char> sta;

		for (int i = S.size(); i >= 0; i--) {
			if (!sta.empty() && sta.top() == S[i]) {
				sta.pop();
			} else {
				sta.push(S[i]);
			}
		}

		while (!sta.empty()) {
			ret += sta.top();
			sta.pop();
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

