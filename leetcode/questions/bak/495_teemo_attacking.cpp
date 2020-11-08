/*************************************************************************
	> File Name: 495_teemo_attacking.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  2/ 7 13:33:10 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, t = 0;
        int len = timeSeries.size();
        if(len > 0){
            t = timeSeries[0] + duration;
            ans += duration;
            for(int i = 1; i < len; i++){
                if(timeSeries[i] >= t){
                    t = timeSeries[i] + duration;
                    ans += duration;
                }
                else{
                    ans += timeSeries[i] + duration - t;
                    t = timeSeries[i] + duration;
                }
            }
        }
        return ans;
    }
};
