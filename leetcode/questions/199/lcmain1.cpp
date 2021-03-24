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
        queue<TreeNode*> q;
        TreeNode *node;

        if (root)
            q.push(root);
        while (!q.empty()){
            int num = q.size();
            for (int i = 0; i < num; i++) {
                node = q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
                if (i == num - 1)
                    ret.push_back(node->val);
            }
        }
        return ret;
    }
};
class Solution {
public:

};

int main(void)
{
	Solution s;

	return 0;
}

