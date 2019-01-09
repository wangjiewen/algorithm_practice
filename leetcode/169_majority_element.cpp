/*************************************************************************
	> File Name: 169_majority_element.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 14:40:36 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        map<int, int> cnt;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(cnt.find(nums[i]) == cnt.end()){
                pair<int,int> p(nums[i],1);
                cnt.insert(p);
            }
            else
                cnt[nums[i]]++;
        }
        for(auto i = cnt.begin(); i != cnt.end(); i++){
            if(i->second > len/2){
                ans = i->first;
                break;
            }
        }
        return ans;
    }
};
