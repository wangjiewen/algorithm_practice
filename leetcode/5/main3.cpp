#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int l, r;
            int begin = 0, len = 0;

            for (int i = 0; i < s.size(); i++) {
                l = r = i;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > len) {
                        begin = l;
                        len = r - l + 1;
                    }
                    l--;
                    r++;
                }
                l = i;
                r = i + 1;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > len) {
                        begin = l;
                        len = r - l + 1;
                    }
                    l--;
                    r++;
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
