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
    TreeNode* prev = nullptr;
    bool alldone = false;
    TreeNode* x = nullptr, *y = nullptr;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(x->val, y->val);
    }
private:
    void inorder(TreeNode* root) {
        if (root == nullptr || alldone) return;

        inorder(root->left);
        if (prev != nullptr && root->val < prev->val) {
            y = root;
            if (x == nullptr) {
                x = prev;
            } else {
                alldone = true;
                return;
            }
        }
        prev = root;
        inorder(root->right);
    }
};