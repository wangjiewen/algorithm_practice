#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int str[256];
            int left = 0, right = 0;
            int len = s.length();
            int ret = 0;

            memset(str, -1, sizeof(str));
            while (right < len) {
                if (str[s[right]] >= 0 && str[s[right]] >= left) {
                    left = str[s[right]] + 1;
                }
                str[s[right]] = right;
                right++;
                ret = max(ret, right - left);
            }
            return ret;
        }
};

int main()
{
    Solution s;
    string str("abcabcbb");
    int ret = s.lengthOfLongestSubstring(str);
    printf("%d\n", ret);
    return 0;
}
