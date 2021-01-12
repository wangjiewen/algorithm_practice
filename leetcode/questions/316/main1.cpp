#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		string ret;
		set<char> letters;

		for (int i = s.size() - 1; i >= 0; i--) {
			if (letters.find(s[i]) == letters.end()) {
				ret += s[i];
				letters.insert(s[i]);
			} else {
				char tail = ret[ret.size() - 1];
				if (s[i] < tail) {
					for (int j = 0; j < ret.size(); j++) {
						if (ret[j] == s[i]) {
							ret.erase(j, 1);
							break;
						}
					}
					ret += s[i];
				}
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main(void)
{
	Solution s;
	string ret;

	ret = s.removeDuplicateLetters("cbacdcbc");
	cout << ret << endl;
	return 0;
}
