#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		for (int i = 0; i < m; i++) {
			int x = i, y = 0;
			int num = matrix[x][y];
			for (; x < m && y < n; x++, y++) {
				if (matrix[x][y] != num) {
					return false;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			int x = 0, y = i;
			int num = matrix[x][y];
			for (; x < m && y < n; x++, y++) {
				if (matrix[x][y] != num) {
					return false;
				}
			}
		}
		return true;
	}

};

int main(void)
{
	Solution s;
	vector<vector<int>> matrix = {{1,2,3,4},
		{5,1,2,3},
		{9,5,1,2}};

	bool ret = s.isToeplitzMatrix(matrix);
	cout << ret << endl;

	return 0;
}

