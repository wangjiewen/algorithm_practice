#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		vector<vector<int>> ret;
		int row = A.size();
		int column = A[0].size();
		for (int i = 0; i < row; i++) {
			vector<int> one;
			for (int j = column - 1; j >= 0; j--) {
				one.push_back(A[i][j]^1);
			}
			ret.push_back(one);
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<vector<int>> A = {{1,1,0}, {1,0,1}, {0,0,0}};

	vector<vector<int>> ret = s.flipAndInvertImage(A);

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}

