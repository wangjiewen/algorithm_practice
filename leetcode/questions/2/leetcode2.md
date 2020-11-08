# leetcode 2 题解

author:Jiewen.Wang

date:2020.7.21

## 2. 两数相加

https://leetcode-cn.com/problems/add-two-numbers/

链表，数学

### 2.1 题目

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例:

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

### 2.2 理解

小学数学的加法，除了统计两个数，需要一个 carry 位。

此外注意链表操作，通过创建一个无用头节点，可以减少边界判断。

### 2.3 代码

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        int c = 0;
        int a, b, sum;

        while (l1 || l2 || c) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            sum = a + b + c;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            c = sum / 10; 
            l1 = l1 ? l1->next : l1; 
            l2 = l2 ? l2->next : l2; 
        }

        // TODO delete head
        return head->next;
    }
};
```