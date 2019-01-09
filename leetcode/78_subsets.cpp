/*************************************************************************
	> File Name: 78_subsets.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  1/12 09:45:27 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > ans(1);
        int numlen = nums.size();
        for(int i = 0; i < numlen; i++){
            int anslen = ans.size();
            for(int j = 0; j < anslen; j++){
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};
