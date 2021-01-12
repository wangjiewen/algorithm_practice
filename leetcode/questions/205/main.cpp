#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

bool solve(string s, string t)
{
	char st[256] = {0}, ts[256] = {0};

	for (int i = 0; i < s.size(); i++) {
		if (st[s[i]] && st[s[i]] != t[i]) {
			return false;
		} else if (ts[t[i]] && ts[t[i]] != s[i]) {
			return false;
		} else{
			st[s[i]] = t[i];
			ts[t[i]] = s[i];
		}
	}
	return true;
}

int main(void)
{
	bool ret;

	ret = solve("13", "24");
	cout << ret << endl;
	return 0;
}
