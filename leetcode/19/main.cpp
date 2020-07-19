#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		struct ListNode *ptr_prev, *ptr, *end;

		ptr_prev = nullptr;
		ptr = end = head;

		for (int i = 0; i < n; i++)
			end = end->next;
		while (end != nullptr) {
			ptr_prev = ptr;
			ptr = ptr->next;
			end = end->next;
		}

		if (ptr_prev) {
			ptr_prev->next = ptr->next;
		} else {
			head = ptr->next;
		}
		delete(ptr);

		return head;
	}

};

int main(void)
{
	struct ListNode *head, *ptr;
	const int len = 5;
	int vec[len] = {1, 2, 3, 4, 5};
	head = ptr = new ListNode(vec[0]);
	for (int i = 1; i < len; i++) {
		ptr->next = new ListNode(vec[i]);
		ptr = ptr->next;
	}

	Solution s;
	ListNode *ret;
	ret = s.removeNthFromEnd(head, 2);

	ptr = ret;
	while (ptr != nullptr) {
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
	return 0;
}
