/*************************************************************************
	> File Name: 287_find_the_duplicate_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 11:06:55 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> x;
        int len = nums.size();
        int ans;
        for(int i = 0; i < len; i++){
            if(x.find(nums[i]) == x.end()){
                x.insert(nums[i]);
            }
            else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
