/*************************************************************************
	> File Name: 121_best_time_to_buy_and_sell_stock.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 14:25:35 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        int tmin, ans;
        tmin = 100000000;
        ans = 0;
        for(int i = 0; i < len; i++){
            tmin = min(prices[i], tmin);
            ans = max(ans, prices[i] - tmin);
        }
        return ans;
    }
};
