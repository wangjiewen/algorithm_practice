/*************************************************************************
	> File Name: 448_find_all_numbers_disappeared_in_an_array.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/18 10:37:28 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        if(len != 0){
            bool cont[len];
            for(int i = 0; i < len; i++)
                cont[i] = false;
            for(int i = 0; i < len; i++)
                cont[ nums[i] - 1 ] = true;
            for(int i = 0; i < len; i++){
                if(cont[i] == false)
                    ans.push_back(i+1);
            }
        }
        return ans;
    }
};
