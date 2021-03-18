#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *bbegin, *begin, *prev, *next, *now;
        int i;

        bbegin = NULL;
        begin = head;
        i = 1;
        while (begin && i < left) {
            bbegin = begin;
            begin = begin->next;
            i++;
        }

        prev = begin;
        now = prev ? prev->next : NULL;
        next = now ? now->next : NULL;
        i++;
        while (now && i <= right) {
            now->next = prev;
            prev = now;
            now = next;
            next = next ? next->next : NULL;
            i++;
        }
        begin->next = now;
        if (bbegin)
            bbegin->next = prev;
        else
            head = prev;
        return head;
    }
};
int main(void)
{
	Solution s;

	return 0;
}

