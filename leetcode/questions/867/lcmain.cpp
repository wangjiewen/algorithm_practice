#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> ret;
		int row = A.size();
		int column = A[0].size();
		for (int i = 0; i < column; i++) {
			vector<int> one;
			for (int j = 0; j < row; j++) {
				one.push_back(A[j][i]);
			}
			ret.push_back(one);
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<vector<int>> A = {{1,2,3}, {4,5,6}, {7,8,9}};

	vector<vector<int>> ret = s.transpose(A);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << ", ";
		}
		cout << endl;
	}

	return 0;
}

