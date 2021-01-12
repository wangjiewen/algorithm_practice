#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> solve(string s) {
	vector<vector<int>> ret;
	int n = s.size();
	int num = 1;

	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] != s[i + 1]) {
			if (num >= 3) {
				ret.push_back({i - num + 1, i});
			}
			num = 1;
		} else {
			num += 1;
		}
	}
	return ret;
}

int main(void)
{
	string s = "dddeeeeaabbb";
	vector<vector<int>> ret = solve(s);

	for (int i = 0; i < ret.size(); i++) {
		printf("%d %d, ", ret[i][0], ret[i][1]);
	}
	printf("\n");
	return 0;
}
