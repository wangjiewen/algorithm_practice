/*************************************************************************
	> File Name: 268_missing_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 16:49:32 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans;
        int len = nums.size();
        ans = (len + 1) * len / 2;
        for(int i = 0; i < len; i++){
            ans -= nums[i];
        }
        return ans;
    }
};
