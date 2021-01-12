/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> lr, rl;
        vector<vector<int>> ret;

        if (!root)
            return ret;

        vector<int> root_arr = {root->val};
        ret.push_back(root_arr);
        rl.push(root);

        while (!lr.empty() || !rl.empty()) {
            vector<int> new_arr;
            TreeNode *head;
            if (!rl.empty()) {
                while (!rl.empty()) {
                    head = rl.top();
                    rl.pop();
                    if (head->right) {
                        new_arr.push_back(head->right->val);
                        lr.push(head->right);
                    }
                    if (head->left) {
                        new_arr.push_back(head->left->val);
                        lr.push(head->left);
                    }
                }
            } else {
                while (!lr.empty()) {
                    head = lr.top();
                    lr.pop();
                    if (head->left) {
                        new_arr.push_back(head->left->val);
                        rl.push(head->left);
                    }
                    if (head->right) {
                        new_arr.push_back(head->right->val);
                        rl.push(head->right);
                    }
                }
            }
            if (!new_arr.empty())
                ret.push_back(new_arr);
        }
        return ret;
    }
};

