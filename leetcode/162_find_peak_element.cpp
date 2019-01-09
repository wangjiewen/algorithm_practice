/*************************************************************************
	> File Name: 162_find_peak_element.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/27 18:23:34 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= nums[ans])
                ans = i;
            else
                break;
        }
        return ans;
    }
};
