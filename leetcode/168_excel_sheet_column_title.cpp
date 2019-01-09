/*************************************************************************
	> File Name: 168_excel_sheet_column_title.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/ 3 17:52:59 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int mod;
        while(1){
            mod = n % 26;
            if(n != 0){
                if(mod != 0){
                    ans += 'A' + (mod - 1);
                    n /= 26;
                }
                else{
                    ans += 'Z';
                    n = n / 26 - 1;
                }
            }
            else
                break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution test;
    string ans;
    ans = test.convertToTitle(n);
    cout << ans << endl;
    return 0;
}
