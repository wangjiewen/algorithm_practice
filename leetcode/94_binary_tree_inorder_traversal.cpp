/*************************************************************************
	> File Name: 94_binary_tree_inorder_traversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/10 10:08:32 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans,tmp;
        if(root != NULL){
            if(root->left != NULL)
                ans = inorderTraversal(root->left);
            ans.push_back(root->val);
            if(root->right != NULL)
                tmp = inorderTraversal(root->right);
            copy(tmp.begin(), tmp.end(), back_inserter(ans));
        }
        return ans;
    }
};
