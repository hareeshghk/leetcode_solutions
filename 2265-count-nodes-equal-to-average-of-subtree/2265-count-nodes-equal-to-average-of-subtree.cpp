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
    int answer = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return answer;
    }

    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto currLeft = dfs(root->left);
        auto currRight = dfs(root->right);

        int newSum = currLeft.first+currRight.first+root->val;
        int newCount = currLeft.second+currRight.second+1;

        if (newSum/newCount == root->val) answer++;

        return {newSum, newCount};
    }
};