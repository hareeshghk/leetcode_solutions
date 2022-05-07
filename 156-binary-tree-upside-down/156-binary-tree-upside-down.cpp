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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return root;
        
        if (root->left == nullptr && root->right == nullptr) return root;
        
        TreeNode* prevRoot = nullptr, *ans = nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        
        while (!q.empty()) {
            auto leftchild = q.front();
            q.pop();
            auto rightchild = q.front();
            q.pop();
            
            if (leftchild->left != nullptr) {
                q.push(leftchild->left);
                q.push(leftchild->right);
            } else {
                ans = leftchild;
            }
            
            leftchild->right = prevRoot;
            leftchild->left = rightchild;
            prevRoot = leftchild;
        }
        
        return ans;
    }
};