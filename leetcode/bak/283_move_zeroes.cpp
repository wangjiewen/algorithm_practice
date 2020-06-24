/*************************************************************************
	> File Name: 283_move_zeroes.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/20 13:38:58 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cont = 0;
        for(auto i = nums.begin();i != nums.end();){
            if(*i == 0){
                i = nums.erase(i);
                cont++;
            }
            else{
                i++;
            }
        }
        while(cont--)
            nums.push_back(0);
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        for(; j < len; j++)
            nums[j] = 0;
    }
};
