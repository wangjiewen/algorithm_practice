#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        struct cmp
        {
            bool operator()(ListNode *a, ListNode *b) {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode *, vector<ListNode *>, cmp> q; 

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode *ret, *ret_ptr;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i])
                    q.push(lists[i]);
            }

            ret = ret_ptr = new ListNode(-1);
            while (!q.empty()) {
                ret_ptr->next = q.top();
                ret_ptr = ret_ptr->next;
                q.pop();
                if (ret_ptr->next) {
                    q.push(ret_ptr->next);
                }
            }

            ret_ptr = ret;
            ret = ret->next;
            delete ret_ptr;
            return ret;
        }
};

void pr_list(ListNode *list)
{
    while (list) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    vector<ListNode*> lists;
    ListNode *node, *head, *prev;
    int tr[3][3] = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6, -1},
    };

    for (int i = 0; i < 3; i++) {
        head = prev = new ListNode(-1);
        for (int j = 0; j < 3 && tr[i][j] > 0; j++) {
            node = new ListNode(tr[i][j]);
            prev->next = node;
            prev = node;
        }
        lists.push_back(head->next);
        pr_list(head->next);
        delete head;
    }


    Solution s;
    ListNode *ret = s.mergeKLists(lists);
    pr_list(ret);

    return 0;
}
