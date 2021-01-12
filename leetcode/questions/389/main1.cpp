#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		char ret = 0;

		for (int i = 0; s[i] != '\0'; i++)
			ret ^= s[i];
		for (int i = 0; t[i] != '\0'; i++)
			ret ^= t[i];

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
