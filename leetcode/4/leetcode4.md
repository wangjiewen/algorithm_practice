# leetcode 4 题解

author:Jiewen.Wang

date:2020.7.28

## 4. 寻找两个正序数组的中位数

https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

归并，二分

### 4.1 题目

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

**示例 1:**

```
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```

**示例 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

### 4.2 理解

归并是第一想法，在归并的基础上优化，根据总个数能找到中位数是第几位。中位数可能由两个或者一个数算出来，可以统一为 (m+n)/2 和 (m+n-1)/2 两个位置上的数字和。或者，假设总数为 m+n=len，如果 len 为奇数，则找第 len/2 位置上的，如果为偶数，则多一个这个位置上前一个位置的，但一定就这俩数就够了。但这种方法的复杂度为 O(m+n)。

题目要求 O(log(m + n))，要到 log 复杂度，势必需要二分了。 

二分的话，可以把问题再细化一下，变成**从两个有序数组中，查找第 K 大的数**，需要 O(log(m+n))，其中 k 就是前面两个中位数的位置。

比较两个数组 i+k/2-1位置上的数，相当于各选出 k/2 - 1 个数，总共选出来 k-2 个数，而其中较小的一半我们就筛掉不要了。k 减去刚刚不要的数，删除数的那个数组，起始位置也要往后挪到删除位置后一位。最后当 k 为 1 时，直接比较两个数组的头就好。此外，还要注意边界情况，一是，当其中一个数组的数已经删除完后，直接从另一个数组中取即可，另一个是，找数组中 k/2-1 的位置时可能越界，取到末尾即可。

### 4.3 代码

O(m+n)

```c++
class Solution {
public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len1 = nums1.size();
            int len2 = nums2.size();
            int len = len1 + len2;
            int i1 = 0, i2 = 0, val1 = 0, val2 = 0;

            for (int i = 0; i <= len / 2; i++) {
                val1 = val2;
                if (i2 >= len2 || (i1 < len1 && nums1[i1] < nums2[i2]))
                    val2 = nums1[i1++];
                else
                    val2 = nums2[i2++];
            }

            if ((len1 + len2) & 1)
                return val2;
            return (val1 + val2) / 2.0;
        }
};
```

O(log(m+n))

```c++
class Solution {
public:
        int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
            int nums1_size = nums1.size();
            int nums2_size = nums2.size();
            int i1 = 0, i2 = 0;
            int new_i1, new_i2;

            while (true) {
                if (i1 == nums1_size)
                    return nums2[i2 + k - 1];
                if (i2 == nums2_size)
                    return nums1[i1 + k - 1];
                if (k == 1)
                    return min(nums1[i1], nums2[i2]);

                new_i1 = min(i1 + k / 2 - 1, nums1_size - 1);
                new_i2 = min(i2 + k / 2 - 1, nums2_size - 1);
                if (nums1[new_i1] <= nums2[new_i2]) {
                    k -= new_i1 - i1 + 1;
                    i1 = new_i1 + 1;
                } else {
                    k -= new_i2 - i2 + 1;
                    i2 = new_i2 + 1;
                }
            }
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len = nums1.size() + nums2.size();

            if (len & 1)
                return getKthElement(nums1, nums2, len / 2 + 1);
            else
                return (getKthElement(nums1, nums2, len / 2) +
                        getKthElement(nums1, nums2, len / 2 + 1)) / 2.0;
        }
};
```

