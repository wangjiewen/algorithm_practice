#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	int row, col;

	void dfs(vector<vector<char>> &board, int x, int y) {
		if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 'O') {
			board[x][y] = 'w';
			dfs(board, x, y+1);
			dfs(board, x, y-1);
			dfs(board, x+1, y);
			dfs(board, x-1, y);
		}
		return;
	}

	void change(vector<vector<char>> &board) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == 'w') {
					board[i][j] = 'O';
				} else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}

public:
	void solve(vector<vector<char>>& board) {
		row = board.size();
		col = board[0].size();
		int x, y;

		x = 0;
		for (y = 0; y < col; y++)
			if (board[x][y] == 'O')
				dfs(board, x, y);
		x = row - 1;
		for (y = 0; y < col; y++)
			if (board[x][y] == 'O')
				dfs(board, x, y);
		y = 0;
		for (x = 0; x < row; x++)
			if (board[x][y] == 'O')
				dfs(board, x, y);
		y = col - 1;
		for (x = 0; x < row; x++)
			if (board[x][y] == 'O')
				dfs(board, x, y);

		change(board);
	}
};

int main(void)
{
	Solution s;
	vector<vector<char>> board = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}};

	s.solve(board);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}

