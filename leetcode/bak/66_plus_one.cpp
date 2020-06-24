/*************************************************************************
	> File Name: 66_plus_one.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/24 10:49:00 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int len = digits.size();
        int c = 0;
        if(digits[len - 1] + 1 < 10){
            digits[len - 1] = digits[len - 1] + 1;
            return digits;
        }
        else{
            ans.insert(ans.begin(), 0);
            c = 1;
        }
        for(int i = len - 2; i >= 0; i--){
            if(digits[i] + c == 10){
                ans.insert(ans.begin(), 0);
                c = 1;
            }
            else{
                ans.insert(ans.begin(), digits[i] + c);
                c = 0;
            }
        }
        if(c != 0){
            ans.insert(ans.begin(), c);
        }
        return ans;
    }
};
