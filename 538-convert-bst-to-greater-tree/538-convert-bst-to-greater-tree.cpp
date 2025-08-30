#include <iostream>

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
    int biggersum;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        biggersum = 0;
        
        reverseinorder(root);
        return root;
    }
    
    void reverseinorder(TreeNode *root) {
        if (root == nullptr) return;
        
        reverseinorder(root->right);
        biggersum += root->val;
        root->val = biggersum;
        reverseinorder(root->left);
    }
};
