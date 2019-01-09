/*************************************************************************
	> File Name: 289_game_of_life.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/24 12:43:36 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n, m;
        n = board.size();
        if(n == 0)
            return;
        m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(judge(board, i, j, n, m))
                    ans[i][j] = 1;
                else
                    ans[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
    
    bool judge(vector<vector<int>>& board, int x, int y, int n, int m){
        int cnt = 0;
        int dx, dy;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0)
                    continue;
                dx = x + i;
                dy = y + j;
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && board[dx][dy] == 1)
                    cnt++;
            }
        }
        if(board[x][y] == 1){
            if(cnt == 2 || cnt == 3)
                return true;
            return false;
        }
        else{
            if(cnt == 3)
                return true;
            return false;
        }
    }
};
