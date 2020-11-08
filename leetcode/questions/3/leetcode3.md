# leetcode 3 题解

author:Jiewen.Wang

date:2020.7.22

12 ms 7MB

## 3. 无重复字符的最长子串

https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

滑窗

### 3.1 题目

给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

### 3.2 理解

通过滑窗记录最长不重复字符，用一个数组记录这个滑窗中出现的字符（因为都是 char 类型，总体量也就 256，如果类型复杂，可以用哈希set，哈希 map 等）。

每次优先向右扩张一位，如果新增的字符在当前滑窗中存在，那么左边就收缩范围，直到新增的不出现在滑窗中。

小优化：

数组记录字符是否存在，改为记录此前存在的位置。左边收缩的时候可以从一位一位扫，变成一个O(1) 的操作，进行一个常数优化。

需要注意，中间位置不会置空，所以判断时，要判断记录的位置是否在滑窗内。

### 3.3 代码

```c++
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int str[256] = {0}; // 初始化0，所以记录的位置是当前位置+1
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
```