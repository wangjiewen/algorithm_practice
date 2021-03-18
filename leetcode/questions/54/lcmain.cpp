#include <bits/stdc++.h>

using namespace std;

#define INVAL -200
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		vector<vector<int>> rol = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int i = 0, j = 0, r = 0;
		int ti, tj;
		int n = matrix.size(), m = matrix[0].size();
		int size = n*m;

		while (ret.size() < size) {
			ret.push_back(matrix[i][j]);
			matrix[i][j] = INVAL;

			ti = i + rol[r][0];
			tj = j + rol[r][1];
			if (ti < n && ti >= 0 && tj < m && tj >=0 && matrix[ti][tj] != INVAL) {
				i = ti;
				j = tj;
			} else {
				r = (r + 1) % 4;
				i = i + rol[r][0];
				j = j + rol[r][1];
			}
		}

		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};

	vector<int> ret = s.spiralOrder(matrix);

	for (auto num : ret)
		cout << num << ", ";
	cout << endl;

	return 0;
}

