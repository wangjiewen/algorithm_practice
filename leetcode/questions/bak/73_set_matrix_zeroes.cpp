/*************************************************************************
	> File Name: 73_set_matrix_zeroes.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/13 14:54:34 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        set<int> col, raw;
        int n, m;
        m = matrix.size();
        if(m == 0)
            return;
        n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    raw.insert(i);
                    col.insert(j);
                }
            }
        }
        set<int>::iterator i;
        for(i = raw.begin(); i != raw.end(); i++)
            for(int j = 0; j < n; j++)
                matrix[*i][j] = 0;
        for(i = col.begin(); i != col.end(); i++)
            for(int j = 0; j < m; j++)
                matrix[j][*i] = 0;
    }
};

