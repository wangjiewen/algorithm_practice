/*************************************************************************
	> File Name: 228_summary_ranges.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  1/12 11:25:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> ans;
        int a,b,t;
        if(len != 0)
            a = t = nums[0];
        if(len == 1){
            string st;
            st = solve(a, t);
            ans.push_back(st);
        }
        for(int i = 1; i < len; i++){
            b = nums[i];
            if(b != t + 1){
                string st;
                st = solve(a, t);
                ans.push_back(st);
                a = t = b;
            }
            else
                t = b;
            if(i == len - 1){
                string st;
                st = solve(a, t);
                ans.push_back(st);
            }
        }
        return ans;
    }
    
    string solve(int a, int b){
        string x, y, st;
        if(a == b)
            st = i2s(a);
        else{
            x = i2s(a);
            y = i2s(b);
            st = x + "->" + y;
        }
        return st;
    }
    
    string i2s(int num){
        char buf[15];
        sprintf(buf, "%d", num);
        string ans = buf;
        return ans;
    }
};
