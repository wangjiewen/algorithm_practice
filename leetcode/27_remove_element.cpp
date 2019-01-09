/*************************************************************************
	> File Name: 27_remove_element.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/23 17:28:36 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for(auto i = nums.begin(); i != nums.end();){
            if(*i == val){
                nums.erase(i);
            }
            else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};
