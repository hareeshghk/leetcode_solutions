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
    int count, ans;
    int kthSmallest(TreeNode* root, int k) {
        count  = 0;
        ans = -1;
        traverse(root, k);
        return ans;
    }
    
    void traverse(TreeNode *root, int k) {
        if (root == nullptr) return;
        
        traverse(root->left, k);
        count++;
        if (count == k) ans =root->val;
        traverse(root->right, k);
    }
};