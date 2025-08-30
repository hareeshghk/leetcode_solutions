#include <algorithm>
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
    int minval;
    int result;
    bool found;
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;

        minval = root->val;
        result = INT_MAX;
        found = false;
        
        dfs(root);
        return found?result:-1;
    }
    
    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        
        if (root->val != minval) {
            result = min(result, root->val);
            found = true;
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
    }
};
