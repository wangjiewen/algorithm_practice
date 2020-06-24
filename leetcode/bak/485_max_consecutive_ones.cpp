/*************************************************************************
	> File Name: 485_max_consecutive_ones.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/18 10:22:37 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == 1){
                temp++;
                if(temp > ans)
                    ans = temp;
            }
            else{
                temp = 0;
            }
        }
        return ans;
    }
};
