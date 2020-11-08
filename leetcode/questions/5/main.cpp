#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        pair<int, int> expand(string &s, int left, int right) {
            while (left >= 0 && right < s.size() &&
                    s[left] == s[right]) {
                left -= 1;
                right += 1;
            }
            return {left + 1, right - 1};
        }
        string longestPalindrome(string s) {
            int start = 0, end = 0;
            for (int i = 0; i < s.size(); i++) {
                auto [left1, right1] = expand(s, i, i);
                auto [left2, right2] = expand(s, i, i+1);
                if (right1 - left1 > end - start) {
                    start = left1;
                    end = right1;
                }
                if (right2 - left2 > end - start) {
                    start = left2;
                    end = right2;
                }
            }
            return s.substr(start, end - start + 1);
        }
};

int main(void)
{
    Solution s;
    string ret = s.longestPalindrome("abbad");
    cout << ret << endl;
    return 0;
}
