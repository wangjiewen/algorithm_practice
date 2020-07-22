#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0, right = 0;
            int len = s.length();
            int ret = 0;
            char c;

            while (right < len) {
                c = s[right];
                for (int i = left; i < right; i++) {
                    if (s[i] == c) {
                        left = i + 1;
                        break;
                    }
                }
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
