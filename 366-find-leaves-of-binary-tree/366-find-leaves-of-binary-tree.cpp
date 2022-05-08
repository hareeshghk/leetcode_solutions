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
    vector<vector<int>> result;
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == nullptr) return result;
        GetHeight(root);
        return result;
    }
    
    int GetHeight(TreeNode * root) {
        if (root == nullptr) return 0;
        
        int h1 = GetHeight(root->left);
        int h2 = GetHeight(root->right);
        
        int cur_height = max(h1,h2);
        if (cur_height == result.size()) result.push_back(vector<int>());
        result[cur_height].push_back(root->val);
        
        return cur_height+1;
    }
};