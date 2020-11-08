#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int expand(string &s, int left, int right) {
            int len = 0;
            while (left >= 0 && right < s.size() &&
                    s[left] == s[right]) {
                left -= 1;
                right += 1;
                len += 1;
            }
            return len - 1;
        }
        string longestPalindrome(string s) {
            int begin = 0, len = 0;
            int temp_begin, temp_len;

            for (int i = 0; i < s.size(); i++) {
                temp_len = expand(s, i, i);
                temp_begin = i - temp_len;
                temp_len = temp_len * 2 + 1;
                if (temp_len > len) {
                    begin = temp_begin;
                    len = temp_len;
                }

                temp_len = expand(s, i, i+1);
                temp_begin = i - temp_len;
                temp_len = temp_len * 2 + 2;
                if (temp_len > len) {
                    begin = temp_begin;
                    len = temp_len;
                }
            }
            return s.substr(begin, len);
        }
};

int main(void)
{
    Solution s;
    string ret = s.longestPalindrome("abbad");
    cout << ret << endl;
    return 0;
}
