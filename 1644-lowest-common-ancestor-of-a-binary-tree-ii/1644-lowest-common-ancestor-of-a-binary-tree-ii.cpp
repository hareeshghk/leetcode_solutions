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
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        findNodes(root, p, q);
        return ans;
    }
    
    bool findNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        
        int curval = (root==p||root == q)?1:0;
        int leftval = findNodes(root->left, p, q)?1:0;
        int rightval = findNodes(root->right, p, q)?1:0;
        
        if (curval + leftval+rightval ==2) ans = root;
        
        return (curval + leftval+rightval > 0);
    }
};
