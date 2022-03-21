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
    int goodNodes(TreeNode* root) {
        return getgoodNodes(root, root->val);
    }
    
    int getgoodNodes(TreeNode* root, int data) {
        if (root==nullptr) return 0;
        int l = getgoodNodes(root->left, max(data, root->val));
        int r = getgoodNodes(root->right, max(data, root->val));
        if (root->val < data) {
            return l+r;
        }
        return 1+l+r;
    }
};