#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n;
    int ret = 1;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool vaild(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &mark, int x, int y) {
        int tx, ty;
        if (vaild(x, y) && mark[x][y] == -1) {
            for (int i = 0; i < 4; i++) {
                tx = x + direction[i][0];
                ty = y + direction[i][1];
                if (vaild(tx, ty) && matrix[tx][ty] > matrix[x][y]) {
                    dfs(matrix, mark, tx, ty);
                    mark[x][y] = max(mark[x][y], mark[tx][ty] + 1);
                }
            }
            mark[x][y] = max(mark[x][y], 1);
            ret = max(mark[x][y], ret);
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> mark(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(matrix, mark, i, j);
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

