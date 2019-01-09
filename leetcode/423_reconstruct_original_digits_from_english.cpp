/*************************************************************************
	> File Name: 423_reconstruct_original_digits_from_english.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  1/ 9 17:35:18 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        int len = s.length();
        int num[26] = {0}, ansn[10] = {0};
        string ans;
        for(int i = 0; i < len; i++){
            num[s[i] - 'a'] ++;
        }
        ansn[0] = num['z' - 'a'];
        num['o' - 'a'] -= ansn[0];
        
        ansn[2] = num['w' - 'a'];
        num['o' - 'a'] -= ansn[2];
        
        ansn[4] = num['u' - 'a'];
        num['o' - 'a'] -= ansn[4];
        num['f' - 'a'] -= ansn[4];
        
        ansn[6] = num['x' - 'a'];
        num['s' - 'a'] -= ansn[6];
        num['i' - 'a'] -= ansn[6];

        ansn[8] = num['g' - 'a'];
        num['h' - 'a'] -= ansn[8];
        num['i' - 'a'] -= ansn[8];

        ansn[1] = num['o' - 'a'];

        ansn[3] = num['h' - 'a'];

        ansn[5] = num['f' - 'a'];
        num['i' - 'a'] -= ansn[5];

        ansn[7] = num['s' - 'a'];

        ansn[9] = num['i' - 'a'];

        for(int i = 0; i < 10; i++)
            for(int j = 0; j < ansn[i]; j++)
                ans += '0' + i;
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution test;
    string ans;
    ans = test.originalDigits(s);
    cout << ans << endl;
    return 0;
}
