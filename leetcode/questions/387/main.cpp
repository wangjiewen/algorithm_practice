#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int letters[26] = {0};
		for (char ch : s) {
			letters[ch - 'a'] += 1;
		}

		for (int i = 0; i < s.size(); i++) {
			if (letters[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

int main(void)
{
	Solution s;
	//string str("leetcode");
	string str("loveleetcode");

	int ret = s.firstUniqChar(str);
	cout << ret << endl;
	return 0;
}
