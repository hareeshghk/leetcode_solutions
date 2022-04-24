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
    vector<vector<int>> ans;
    vector<vector<int>> findLeaves(TreeNode* root) {
        findHeight(root);
        return ans;
    }
    int findHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int h1 = findHeight(root->left);
        int h2 = findHeight(root->right);
        int root_height = max(h1,h2);
        if(ans.size() <= root_height) {
            ans.push_back({});
        }
        ans[root_height].push_back(root->val);
        return root_height+1;
    }
};