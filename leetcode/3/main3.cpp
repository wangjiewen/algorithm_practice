#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_set<int> now;
        int head = 0, tail = 0;
        int len = s.length();
        int ret = 0;

        while (head < len) {
            while (tail < len && !now.count(s[tail])) {
                now.insert(s[tail]);
                tail += 1;
            }
            ret = max(ret, tail - head);
            now.erase(s[head]);
            head += 1;
        }
        return ret;
    }

int main(void)
{
    string s("aab");
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);
}
