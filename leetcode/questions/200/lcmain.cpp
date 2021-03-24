#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    int m, n;

    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
            grid[x][y] = '0';
            dfs(grid, x, y+1);
            dfs(grid, x, y-1);
            dfs(grid, x+1, y);
            dfs(grid, x-1, y);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ret = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')
                    continue;
                dfs(grid, i, j);
                ret += 1;
            }
        }

        return ret;
    }
};
class Solution {
public:

};

int main(void)
{
	Solution s;

	return 0;
}

