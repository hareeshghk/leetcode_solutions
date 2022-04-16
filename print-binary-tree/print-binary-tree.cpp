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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> result;
        
        if (root == nullptr) return result;
        
        int height = getHeight(root)-1;
        
        int rows = height+1;
        int columns = (1<<(height+1)) - 1;
        result.resize(rows, vector<string>(columns, ""));
        
        Traverse(root, 0, 0, columns-1, result);
        return result;
    }
    
    void Traverse(TreeNode *root, int r, int left, int right, vector<vector<string>> &result) {
        if (root == nullptr) return;
        int mid = (left+right)/2;
        result[r][mid] = to_string(root->val);
        Traverse(root->left, r+1, left, mid-1,result);
        Traverse(root->right, r+1, mid+1,right,result);
    }
    
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        
        int h1 = getHeight(root->left);
        int h2 = getHeight(root->right);
        return max(h1,h2)+1;
    }
};