/*************************************************************************
	> File Name: 263_ugly_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/11 11:57:36 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num > 0){
            while(num % 2 == 0)
                num /= 2;
            while(num % 3 == 0)
                num /= 3;
            while(num % 5 == 0)
                num /= 5;
            if(num == 1)
                return true;
        }
        return false;
    }
};
