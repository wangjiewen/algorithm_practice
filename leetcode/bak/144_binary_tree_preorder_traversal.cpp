/*************************************************************************
	> File Name: 144_binary_tree_preorder_traversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/18 10:12:49 2017
 ************************************************************************/

#include<iostream>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans,temp;
        if(root != NULL){
            ans.push_back(root->val);
            if(root->left != NULL){
                temp = preorderTraversal(root->left);
                copy(temp.begin(), temp.end(), back_inserter(ans));
            }
            if(root->right != NULL){
                temp = preorderTraversal(root->right);
                copy(temp.begin(), temp.end(), back_inserter(ans));
            }
        }
        return ans;
    }
};
