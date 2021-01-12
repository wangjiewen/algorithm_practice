#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		int letters[26] = {0};
		string ret;

		for (int i = 0; i < s.size(); i++)
			letters[s[i] - 'a'] = 1;
		for (int i = 0; i < 26; i++) {
			if (letters[i] != 0) {
				char c = 'a' + i;
				ret += c;
			}
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	string ret;

	ret = s.removeDuplicateLetters("ddea");
	cout << ret << endl;
	return 0;
}
