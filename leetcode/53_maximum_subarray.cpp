/*************************************************************************
	> File Name: 53_maximum_subarray.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 15:01:26 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int dp[len], ans;
        ans = dp[0] = nums[0];
        for(int i = 1; i < len; i++){
            dp[i] = nums[i];
            if(dp[i-1] > 0){
                dp[i] += dp[i-1];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
