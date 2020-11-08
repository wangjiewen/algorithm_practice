# leetcode 1 题解

## 1. 两数之和

https://leetcode-cn.com/problems/two-sum/

简单，暴力，哈希表

### 1.1 题目

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

### 1.2 理解

第一想法是暴力，两重循环就可以解决，复杂度 O(n<sup>2</sup>)，leetcode 上能过，但显然不是面试能过的。

需要优化，首先考虑第一个大循环是优化不了的，但第二个数是能确认的，我们需要的就是 target - nums[first]，怎么能快速找出第二个数，是可以优化的点。

考虑用哈希表，能将查找时间从 O(n) 降到 O(1)。

这里用点小技巧，把创建哈希表和遍历循环放在一起，循环时判断目标数不在哈希表中时，将这个数放入表中。

总体复杂度为 O(n)。

c++ stl 中使用 unordered_map 或者 unordered_set，内部实现是哈希表的方式。

### 1.3 代码

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end())
                return {i, m[target - nums[i]]};
            m[nums[i]]= i;
        }
    return {};
    }
};
```