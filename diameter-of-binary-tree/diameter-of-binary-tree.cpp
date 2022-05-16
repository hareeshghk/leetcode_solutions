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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        GetHeight(root);
        
        return diameter==0?0:diameter-1;
    }
    
    int GetHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        
        int h_left = GetHeight(root->left);
        int h_right = GetHeight(root->right);
        
        diameter = max(diameter, h_left+h_right+1);
        
        return max(h_left, h_right)+1;
    }
};