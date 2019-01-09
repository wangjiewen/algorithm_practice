/*************************************************************************
	> File Name: 62_unique_paths.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 14:40:00 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int x[m][n];
        for(int i = 0; i < m; i++)
            x[i][0] = 1;
        for(int i = 0; i < n; i++)
            x[0][i] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                x[i][j] = x[i][j-1] + x[i-1][j];
        }
        return x[m-1][n-1];
    }
};
