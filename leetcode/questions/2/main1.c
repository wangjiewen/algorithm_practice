#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void insert(struct ListNode **head, struct ListNode **tail, struct ListNode *new)
{
    if (!*head) {
        *head = new;
    } else {
        (*tail)->next = new;
    }
    *tail = new;
}

void malloc_list(struct ListNode **new, int val)
{
    *new = (struct ListNode*)malloc(sizeof(struct ListNode));
    (*new)->next = NULL;
    (*new)->val = val;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l = NULL, *tail, *new;
    int a, b, c = 0;
    
    while (l1 || l2) {
        if (!l1) {
            a = 0;
        } else {
            a= l1->val;
			l1 = l1->next;
		}
        
        if (!l2) {
            b = 0;
        } else {
            b = l2->val;
			l2 = l2->next;
		}
        
        c = a + b + c;
        malloc_list(&new, 0);
        if (c < 10) {
            new->val = c;
            c = 0;
        } else {
            new->val = c - 10;
            c = 1;
        }
        
        insert(&l, &tail, new);
    }

	if (c != 0) {
		malloc_list(&new, 1);
		insert(&l, &tail, new);
	}
    
    return l;
}

void list_print(struct ListNode *l)
{
    while(l) {
        printf("%d ", l->val);
        l = l->next;
    }
	printf("\n");
}

int main(){
    int a = 81, b = 0;
    struct ListNode *l1 = NULL, *l2 = NULL, *l, *tail, *new;
    
    for (; a > 0; a /= 10) {
        malloc_list(&new, a % 10);
        insert(&l1, &tail, new);
    }
	list_print(l1);
    
    for (; b > 0; b /= 10) {
        malloc_list(&new, b % 10);
        insert(&l2, &tail, new);
    }
        malloc_list(&new, b);
        insert(&l2, &tail, new);
	list_print(l2);
    
    l = addTwoNumbers(l1, l2);
    list_print(l);
}
