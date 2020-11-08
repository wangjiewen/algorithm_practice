# leetcode 5 题解

author:Jiewen.Wang

date:2020.7.29

## 5. 最长回文子串

https://leetcode-cn.com/problems/longest-palindromic-substring/

中心扩展

### 5.1 题目

给定一个字符串 `s`，找到 `s` 中最长的回文子串。你可以假设 `s` 的最大长度为 1000。

**示例 1:**

```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```

**示例 2:**

```
输入: "cbbd"
输出: "bb"
```

### 5.2 理解

最长回文子串是一道很经典的题，通过 Manacher 算法可以把复杂度做到 O(n)。一般面试不会到这个难度吧，所以这里只记录比较好理解的**中心扩展**的方法，后续有机会再补充 O(n) 方法。

怎么判断一个串是回文串？比较头尾是否相同一直递减比较到中间。我们换一下思路，从中心开始，往外扩展比较。从而找到以这个点为中心，最长的回文子串。注意，需要考虑长度为奇数（中心1个数），和长度为偶数（中心两个数），两种情况。时间复杂度 O(n^2)。

### 5.3 代码

```c++
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
```

## 5.4 其他思路

动态规划：`dp[i][j]` 表示从 i 到 j 是否为回文串，所以有转移方程， `dp[i][j]=(s[i]==s[j])?dp[i+1][j-1]:false`。边界条件需要 i==j 和 j-i==1 两种情况。





更多题解及代码打磨记录，欢迎关注我的专栏和我的 github 仓库。

https://zhuanlan.zhihu.com/c_1268715857842393088

https://github.com/wangjiewen/algorithm_practice