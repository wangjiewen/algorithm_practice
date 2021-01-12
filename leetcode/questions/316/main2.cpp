#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
#define N 26
	string removeDuplicateLetters(string s) {
		int nums[N] = {0};
		int visable[N] = {0};
		string ret;

		for (char c : s) {
			nums[c - 'a'] += 1;
		}

		for (char c : s) {
			if (!visable[c-'a']) {
				while (!ret.empty() && ret.back() > c) {
					if (nums[ret.back() - 'a']) {
						visable[ret.back() - 'a'] = 0;
						ret.pop_back();
					} else {
						break;
					}
				}
				ret += c;
				visable[c - 'a'] = 1;
			}
			nums[c - 'a'] -= 1;
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	string ret;

	//ret = s.removeDuplicateLetters("cbacdcbc");
	ret = s.removeDuplicateLetters("bcabc");
	cout << ret << endl;
	return 0;
}
