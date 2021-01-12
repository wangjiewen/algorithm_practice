#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> solve(string s) {
	vector<vector<int>> ret;
	char prev = 0;
	int begin = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != prev) {
			if (i - begin >= 3) {
				vector<int> new_vec = {begin, i - 1};
				ret.push_back(new_vec);
			}
			prev = s[i];
			begin = i;
		}
	}
	if (s.size() - begin >= 3) {
		vector<int> new_vec = {begin, s.size() - 1};
		ret.push_back(new_vec);
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
