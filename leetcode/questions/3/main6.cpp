#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> m;
            int left = 0, right = 0;
            int len = s.length();
            int ret = 0;

            while (right < len) {
                if (m.find(s[right]) != m.end() && m[s[right]] >= left) {
                    left = m[s[right]] + 1;
                }
                m[s[right]] = right;
                right++;
                ret = max(ret, right - left);
            }
            return ret;
        }
};

int main()
{
    Solution s;
    string str("abba");
    int ret = s.lengthOfLongestSubstring(str);
    printf("%d\n", ret);
    return 0;
}
