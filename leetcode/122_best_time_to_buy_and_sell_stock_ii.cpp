/*************************************************************************
	> File Name: 122_best_time_to_buy_and_sell_stock_ii.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 14:28:21 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int a, b, i, j;
        int len = prices.size();
        if(len < 2)
            return 0;
        i = 0;
        while(i < len){
            i = down(prices, i);
            j = up(prices, i);
            ans += prices[j] - prices[i];
            i = j + 1;
        }
        return ans;
    }
    int up(vector<int>& prices, int i){
        int j = i + 1;
        int len = prices.size();
        int x = prices[i];
        while(j < len && prices[j] >= x){
            x = prices[j];
            j++;
        }
        return j-1;
    }
    int down(vector<int>& prices, int i){
        int j = i + 1;
        int len = prices.size();
        int x = prices[i];
        while(j < len && prices[j] <= x){
            x = prices[j];
            j++;
        }
        return j-1;
    }
};
