#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int str[256] = {0};
            int left = 0, right = 0;
            int len = s.length();
            int ret = 0;

            while (right < len) {
                if (str[s[right]] && str[s[right]] - 1 >= left) {
                    left = str[s[right]];
                }
                str[s[right]] = right + 1;
                right++;
                ret = max(ret, right - left);
            }
            return ret;
        }
};

int main()
{
    Solution s;
    string str("abcbcbb");
    int ret = s.lengthOfLongestSubstring(str);
    printf("%d\n", ret);
    return 0;
}
