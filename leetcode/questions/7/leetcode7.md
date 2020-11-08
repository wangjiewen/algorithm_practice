# leetcode 7 题解

author:Jiewen.Wang

date:2020.9.7

## 7. 整数反转

https://leetcode-cn.com/problems/reverse-integer/

边界条件，溢出

### 7.1 题目

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

**示例 1:**

```
输入: 123
输出: 321
```

**示例 2:**

```
输入: -123
输出: -321
```

**示例 3:**

```
输入: 120
输出: 21
```

**注意:**

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

### 7.2 理解

简单问题，核心操作就是 ret = ret * 10 + num % 10，num = num /10 循环即可。

主要考虑边界条件，既溢出的问题。

INT_MAX 为 2147483647，INT_MIN 为 -2147483648。



当 ret * 10 + num % 10 > INT_MAX 或 < INT_MIN 时溢出，则

1. ret > INT_MAX 或 ret < INT_MIN
2. ret == INT_MAX 且 num % 10 > 7
3. ret == INT_MIN 且 num % 10 < -8

注意输入，输入也是 32位有符号整数，在这个输入范围内，反转时并不会出现后面两种情况，边界时最高位只会是 2，不会到 7 8 9。所以条件有第一个其实就够了。

### 7.3 代码

```c++
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            if (ret > INT_MAX/10 || ret < INT_MIN/10)
                return 0;
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};
```



更多题解及代码打磨记录，欢迎关注我的专栏和我的 github 仓库。

https://zhuanlan.zhihu.com/c_1268715857842393088

https://github.com/wangjiewen/algorithm_practice