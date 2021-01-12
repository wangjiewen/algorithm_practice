#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		char ret = 0;
		int i = 0;

		while (s[i] != '\0' && t[i] != '\0') {
			ret += t[i];
			ret -= s[i];
			i++;
		}
		ret += t[i];

		return ret;
	}
};

int main(void)
{
	Solution sol;
	char ret;
	string s(""), t("y");

	ret = sol.findTheDifference(s, t);

	cout << ret << endl;
	return 0;
}
