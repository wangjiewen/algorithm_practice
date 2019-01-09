/*************************************************************************
	> File Name: 217_contains_duplicate.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 16:45:39 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        set<int> x;
        for(int i = 0; i < len; i++){
            x.insert(nums[i]);
        }
        if(x.size() < len)
            return true;
        else
            return false;
    }
};
