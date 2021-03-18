#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n, vector<int>(n, 0));
		vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int num = 1, i = 0, j = 0, d = 0;
		int ti, tj;

		while (num <= n * n) {
			ret[i][j] = num;

			ti = i + dir[d][0];
			tj = j + dir[d][1];
			if (ti >= n || ti < 0 || tj >=n || tj < 0 || ret[ti][tj] != 0)
				d = (d + 1) % 4;
			i += dir[d][0];
			j += dir[d][1];
			num += 1;
		}

		return ret;
	}

};

int main(void)
{
	Solution s;
	vector<vector<int>> ret = s.generateMatrix(4);

	for (auto i : ret) {
		for (auto j : i) {
			cout << j << ", ";
		}
		cout << endl;
	}

	return 0;
}

