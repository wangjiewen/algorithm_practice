#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

        return head->next;
    }
};

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {0};
    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-1);
    ListNode *cur;

    cur = l1;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    l1 = l1->next;

    cur = l2;
    for (int i = 0; i < sizeof(b)/sizeof(int); i++) {
        cur->next = new ListNode(b[i]);
        cur = cur->next;
    }
    l2 = l2->next;

    Solution s;
    ListNode *l = s.addTwoNumbers(l1, l2);

    cur = l;
    while(cur) {
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
}
