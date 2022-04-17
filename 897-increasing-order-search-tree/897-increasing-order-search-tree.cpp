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
    TreeNode *iter;
    TreeNode* increasingBST(TreeNode* root) {
        auto head = new TreeNode(-1);
        iter = head;
        InOrder(root);
        return head->right;
    }
    
    void InOrder(TreeNode *root) {
        if (root==nullptr) return;
        
        InOrder(root->left);
        iter->right = root;
        root->left = nullptr;
        iter = root;
        InOrder(root->right);
    }
};