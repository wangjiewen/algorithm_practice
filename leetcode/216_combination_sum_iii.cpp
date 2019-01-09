/*************************************************************************
	> File Name: 216_combination_sum_iii.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 10:41:56 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> x;
        signalSum(ans, x, k, n, 0);
        return ans;
    }
    void signalSum(vector<vector<int>>& ans, vector<int> x, int k, int n, int p){
        int a = p + 1;
        if(k == 1){
            if(n > 0 && n < 10){
                x.push_back(n);
                ans.push_back(x);
            }
            return;
        }
        while(n - a > a && a < 10){
            x.push_back(a);
            signalSum(ans, x, k - 1, n - a, a);
            x.pop_back();
            a++;
        }
        return;
    }
};
