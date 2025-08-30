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
    int maxdepth;
    TreeNode *result;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return root;
        maxdepth = 0;
        result = nullptr;
        dfs(root, 0);
        heights(root, 0, maxdepth);
        return result;
    }
    
    void dfs(TreeNode *root, int d) {
        if(root == nullptr) return;
        maxdepth = max(maxdepth, d);
        dfs(root->left, d+1);
        dfs(root->right, d+1);
    }
    
    int heights(TreeNode *root, int d, int maxdepth) {
        if(root == nullptr) return 0;
        
        int h1 = heights(root->left, d+1, maxdepth);
        int h2 = heights(root->right, d+1, maxdepth);
        if(h1+d == maxdepth && h2+d ==maxdepth) result = root;
        return max(h1,h2)+1;
    }
};
