/*************************************************************************
	> File Name: 167_two_sum_ii_-_input_array_is_sorted.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/18 13:19:59 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        bool flag = false;
        vector<int> ans;
        for(int i = 0; i < len; i++){
            for(int j= 0; j < i; j++){
                if(numbers[i] + numbers[j] == target){
                    ans.push_back(j+1);
                    ans.push_back(i+1);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, j;
        vector<int> ans;
        i = 0;
        j = numbers.size() - 1;
        while(1){
            if(numbers[i] + numbers[j] < target)
                i++;
            else if(numbers[i] + numbers[j] > target)
                j--;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};
