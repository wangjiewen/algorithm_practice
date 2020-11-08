#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

// dp[i] means 前 i 个字符组成的字符串是否可以拆分
// dp[i] = dp[j] && check(j...i-1)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> w;
        const int len = s.length();
        bool dp[len+1];

        for (int i = 0; i < wordDict.size(); i++) {
            w.insert(wordDict[i]);
        }

        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            dp[i] = false;
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string ts(s, j, i - j);
                    //cout << ts << endl;
                    if (w.count(ts)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            //printf("dp[%d]=%d\n", i, dp[i]);
        }
        return dp[len];
    }

int main(void)
{
    string s("catsandog");
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    bool ret = wordBreak(s, wordDict);

    printf("%d\n", ret);

    return 0;
}
