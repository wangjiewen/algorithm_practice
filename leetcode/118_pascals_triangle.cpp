/*************************************************************************
	> File Name: 118_pascals_triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/24 11:00:00 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int n = 0; n < numRows; n++){
            if(n == 0){
                vector<int> ta(1, 1);
                ans.push_back(ta);
            }
            else if(n == 1){
                vector<int> ta(2, 1);
                ans.push_back(ta);
            }
            else{
                vector<int> ta;
                ta.push_back(1);
                for(int i = 1; i < n; i++){
                    ta.push_back(ans[n-1][i-1] + ans[n-1][i]);
                }
                ta.push_back(1);
                ans.push_back(ta);
            }
        }
        return ans;
    }
};
