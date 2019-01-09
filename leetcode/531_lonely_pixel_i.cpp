/*************************************************************************
	> File Name: 531_lonely_pixel_i.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/ 6 17:21:50 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        if(n == 0)
            return 0;
        int m = picture[0].size();
        vector<int> ncnt(n,0), mcnt(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 'B'){
                    ncnt[i]+=1;
                    mcnt[j]+=1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 'B' && ncnt[i] == 1 && mcnt[j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

