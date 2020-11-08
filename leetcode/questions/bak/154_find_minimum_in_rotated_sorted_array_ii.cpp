/*************************************************************************
	> File Name: 154_find_minimum_in_rotated_sorted_array_ii.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/24 15:01:09 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int len = nums.size();
        for(int i = 1; i < len; i++){
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};
