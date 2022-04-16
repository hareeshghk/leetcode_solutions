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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        int rightSum = GetSum(root->right, 0);
        root->val += rightSum;
        GetSum(root->left, root->val);
        return root;
    }
    
    int GetSum(TreeNode *root, int prevSum) {
        if (root == nullptr) return 0;
        
        int rightSum = GetSum(root->right, prevSum);
        int leftSum = GetSum(root->left, root->val+rightSum+prevSum);
        int result = root->val + leftSum + rightSum;
        root->val += rightSum + prevSum;
        return result;
    }
};