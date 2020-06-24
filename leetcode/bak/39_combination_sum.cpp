/*************************************************************************
	> File Name: 39_combination_sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/27 17:40:48 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> one;
        solve(ans, candidates, one, target);
        return ans;
    }
    void solve(vector<vector<int>>& ans, vector<int>& candidates, vector<int> one, int target) {
        if(target == 0){
            ans.push_back(one);
            return;
        }
        for(int i = 0; i < candidates.size(); i++){
            int x = candidates[i];
            if((one.empty() || *(one.rbegin()) <= x) && target - x >= 0){
                one.push_back(x);
                solve(ans, candidates, one, target - x);
                one.pop_back();
            }
            else{
                continue;
            }
        }
    }
};
