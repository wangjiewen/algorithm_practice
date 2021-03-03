#include <bits/stdc++.h>

using namespace std;

#define N 1005

class NumMatrix {
private:
	vector<vector<int>> sum;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row <= 0)
			return;
		int col = matrix[0].size();
		sum.resize(row + 1, vector<int>(col + 1));
		for (int i = 0; i < row; i++) {
			int temp = 0;
			for (int j = 0; j < col; j++) {
				temp += matrix[i][j];
				sum[i+1][j+1] = sum[i][j+1] + temp;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum[row2+1][col2+1] + sum[row1][col1] -
			sum[row2+1][col1] - sum[row1][col2+1];
	}
};

int main(void)
{
	vector<vector<int>> matrix = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};
	NumMatrix *obj = new NumMatrix(matrix);
	cout << obj->sumRegion(2,1,4,3) << endl;
	cout << obj->sumRegion(1,1,2,2) << endl;
	cout << obj->sumRegion(1,2,2,4) << endl;


	return 0;
}

