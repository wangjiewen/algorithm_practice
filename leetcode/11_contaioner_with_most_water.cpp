/*************************************************************************
	> File Name: 11_contaioner_with_most_water.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/ 7 13:55:16 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int h = min(height[i], height[j]);
            ans = max(ans, h * (j - i));
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return ans;
    }
};
