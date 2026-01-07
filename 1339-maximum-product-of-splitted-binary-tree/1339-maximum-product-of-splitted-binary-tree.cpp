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
    long long totalSum, maximumProduct;
public:
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        maximumProduct = 1;
        getMaxProduct(root);
        return (int)(maximumProduct % 1000000007);
    }
private:
    int getTotalSum(TreeNode* root) {
        if (root  == nullptr) return 0;

        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    int getMaxProduct(TreeNode* root) {
        if (root == nullptr) return 0;

        int currentSubTreeSum = root->val + getMaxProduct(root->left) + getMaxProduct(root->right);

        maximumProduct = max(maximumProduct, (totalSum-currentSubTreeSum) * currentSubTreeSum);
        return currentSubTreeSum;
    }
};