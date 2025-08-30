#include <cmath>
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
    int ans;
    int distributeCoins(TreeNode* root) {
        ans = 0;
        countCoins(root);
        return ans;
    }
    
    int countCoins(TreeNode* root) {
        if (root == nullptr) return 0;
        int c1 = countCoins(root->left);
        int c2 = countCoins(root->right);
        
        if (c1 != 0) ans += abs(c1);
        
        if (c2 != 0) ans += abs(c2);
        
        int remaining = root->val + c1 + c2;
        return remaining - 1;
    }
};
