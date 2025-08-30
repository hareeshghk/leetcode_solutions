#include <iostream>
using namespace std;

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
    int maxdepth, result;
    int deepestLeavesSum(TreeNode* root) {
        maxdepth = -1;
        result = 0;
        
        traverse(root, 0);
        return result;
    }
    
    void traverse(TreeNode *root, int depth) {
        if (root == nullptr) {
            return;
        }
        
        if (depth > maxdepth) {
            maxdepth = depth;
            result = root->val;
        } else if (depth == maxdepth) {
            result += root->val;
        }
        
        traverse(root->left, depth+1);
        traverse(root->right, depth+1);
    }
};
