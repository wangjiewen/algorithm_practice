/*************************************************************************
	> File Name: 299_majority_element_ii.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/17 16:04:04 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        int x = len / 3;
        map<int, int> cont;
        vector<int> ans;
        for(int i = 0; i < len; i++){
            if(cont.find(nums[i]) == cont.end()){
                pair<int, int> ad(nums[i], 1);
                cont.insert(ad);
            }
            else{
                cont[nums[i]]++;
            }
        }
        for(auto i = cont.begin(); i != cont.end(); i++){
            if(i->second > x)
                ans.push_back(i->first);
        }
        return ans;
    }
};
