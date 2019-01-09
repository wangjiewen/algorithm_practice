/*************************************************************************
	> File Name: 442_find_all_duplicates_in_an_array.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/18 10:55:27 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        if(len != 0){
            int cont[len];
            for(int i = 0; i < len; i++)
                cont[i] = 0;
            for(int i = 0; i < len; i++)
                cont[ nums[i] - 1 ]++;
            for(int i = 0; i < len; i++){
                if(cont[i] == 2)
                    ans.push_back(i+1);
            }
        }
        return ans;
    }
};
