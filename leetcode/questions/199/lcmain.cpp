#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q1, q2;
        TreeNode *node;

        if (root)
            q1.push(root);
        while (!q1.empty() || !q2.empty()){
            while (!q1.empty()) {
                node = q1.front();
                if (node->left)
                    q2.push(node->left);
                if (node->right)
                    q2.push(node->right);
                q1.pop();
                if (q1.empty())
                    ret.push_back(node->val);
            }

            while (!q2.empty()) {
                node = q2.front();
                if (node->left)
                    q1.push(node->left);
                if (node->right)
                    q1.push(node->right);
                q2.pop();
                if (q2.empty())
                    ret.push_back(node->val);
            }
        }
        return ret;
    }
};

int main(void)
{
	Solution s;

	return 0;
}

