#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> &matrix);
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> temp = matrix;
		int n = matrix.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = matrix[n - 1 - j][i];
		matrix = temp;
	}
};

void print_matrix(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << ", ";
		cout << endl;
	}
}

int main(void)
{
	Solution s;
	vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

	s.rotate(matrix);
	print_matrix(matrix);
	return 0;
}
