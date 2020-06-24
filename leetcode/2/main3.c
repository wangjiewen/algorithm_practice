#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *cur = head;
	int c = 0;
	int a, b, sum;

	while (l1 || l2 || c) {
		a = l1 ? l1->val : 0;
		b = l2 ? l2->val : 0;
		sum = a + b + c;
		cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = sum % 10;
		c = sum / 10;
		l1 = l1 ? l1->next: l1;
		l2 = l2 ? l2->next: l2;
	}
	cur = head->next;
	free(head);

	return cur;
}

void list_print(struct ListNode *l)
{
    while(l) {
        printf("%d ", l->val);
        l = l->next;
    }
	printf("\n");
}

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(int))
int main(void){
    int a[] = {8, 1};
	int b[] = {0};
    struct ListNode *l1, *l2, *l, *cur;
    
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur = l1;
    for (int i = 0; i < ARRAY_SIZE(a); i++) {
		cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = a[i];
    }
	cur = l1->next;
	free(l1);
	l1 = cur;
	list_print(l1);

    l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur = l2;
    for (int i = 0; i < ARRAY_SIZE(b); i++) {
		cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur = cur->next;
		cur->val = b[i];
    }
	cur = l2->next;
	free(l2);
	l2 = cur;
	list_print(l2);
    
    l = addTwoNumbers(l1, l2);
    list_print(l);

	return 0;
}
