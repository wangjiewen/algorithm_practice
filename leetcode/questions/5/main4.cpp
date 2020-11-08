#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int begin = 0, len = 0;

        void expand(string &s, int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    begin = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        string longestPalindrome(string s) {
            for (int i = 0; i < s.size(); i++) {
                expand(s, i, i);
                expand(s, i, i + 1);
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
