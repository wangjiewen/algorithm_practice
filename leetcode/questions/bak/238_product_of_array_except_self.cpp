/*************************************************************************
	> File Name: 238_product_of_array_except_self.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  2/ 7 15:27:18 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int x = 1, t;
        vector<int> ans;
        for(int i = 0; i < len; i++){
            x *= nums[i];
        }
        if(x != 0){
            for(int i = 0; i < len; i++){
                t = x / nums[i];
                ans.push_back(t);
            }
        }
        else{
            for(int i = 0; i < len; i++){
                if(nums[i] == 0){
                    x = 1;
                    for(int j = 0; j < len; j++){
                        if(j != i)
                          x *= nums[j];  
                    }
                    ans.push_back(x);
                }
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};
