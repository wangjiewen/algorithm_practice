#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        set<int> now;
        int head = 0, tail = 0;
        int len = s.length();
        int ret = 0;

        while (tail < len) {
            while (head < tail && s[head] != s[tail]) {
                now.erase(s[head]);
                head += 1;
            }
            if (head < tail && s[head] == s[tail]) {
                now.erase(s[head]);
                head += 1;
            }
            while (tail < len && now.find(s[tail]) == now.end()) {
                now.insert(s[tail]);
                tail += 1;
            }
            ret = max(ret, tail - head);
        }
        return ret;
    }

int main(void)
{
    string s("aab");
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);
}
