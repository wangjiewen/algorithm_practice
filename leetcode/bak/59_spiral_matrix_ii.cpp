/*************************************************************************
	> File Name: 59_spiral_matrix_ii.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/22 15:22:03 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int i, j, t, dr;
        int x[4]={0,1,0,-1}, y[4]={1,0,-1,0};
        i = j = 0;
        t = 1;
        dr = 0; //0:right, 1:down, 2:left, 3:up
        int k = n * n;
        while(k--){
            ans[i][j] = t;
            t++;
            if(i + x[dr] < 0 || i + x[dr] >= n || j + y[dr] < 0 || j + y[dr] >= n || ans[i+x[dr]][j+y[dr]] != 0){
                dr = (dr + 1) % 4;
            }
            i = i + x[dr];
            j = j + y[dr];
        }
        return ans;
    }
};
