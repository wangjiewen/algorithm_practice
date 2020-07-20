#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *ret_ptr = new ListNode(0);
		ListNode *head = ret_ptr;
		while (l1 && l2) {
			while (l1 && l2 && l1->val < l2->val) {
				ret_ptr->next = l1;
				l1 = l1->next;
				ret_ptr = ret_ptr->next;
			}
			while (l1 && l2 && l1->val >= l2->val) {
				ret_ptr->next = l2;
				l2 = l2->next;
				ret_ptr = ret_ptr->next;
			}
		}
		if (l1) {
			ret_ptr->next = l1;
		} else if (l2) {
			ret_ptr->next = l2;
		}

		head = head->next;
		return head;
	}
};

void print_list(ListNode *l)
{
	while (l) {
		printf("%d ", l->val);
		l = l->next;
	}
	printf("\n");
}

int main(void)
{
	int l1v[] = {1, 2, 4};
	int l2v[] = {1, 3, 4};
	ListNode *l1 = nullptr, *l2 = nullptr;
	int len;

	len = sizeof(l1v) / sizeof(int);
	for (int i = len - 1; i >= 0 ; i--)
		l1 = new ListNode(l1v[i], l1);
	print_list(l1);

	len = sizeof(l2v) / sizeof(int);
	for (int i = len - 1; i >= 0 ; i--)
		l2 = new ListNode(l2v[i], l2);
	print_list(l2);

	Solution s;
	ListNode *ret = s.mergeTwoLists(l1, l2);

	while(ret) {
		printf("%d ", ret->val);
		ret = ret->next;
	}
	printf("\n");
	return 0;
}
