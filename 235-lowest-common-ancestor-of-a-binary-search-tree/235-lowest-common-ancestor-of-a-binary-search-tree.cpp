#include <iostream>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        return findancestor(root, p, q);
    }
    
    TreeNode* findancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((p->val <= root->val) && (root->val <= q->val)) return root;
        
        if (q->val < root->val) return findancestor(root->left, p, q);
        else return findancestor(root->right, p, q);
    }
};
