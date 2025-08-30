#include <iostream>
#include <utility>

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       auto [lca, depth] = getLCA(root, 0);
       return lca; 
    }
private:
    pair<TreeNode*, int> getLCA(TreeNode* root, int depth) {
        if (root == nullptr) {
            return {root, depth};
        }

        auto [ca1, d1] = getLCA(root->left, depth + 1);
        auto [ca2, d2] = getLCA(root->right, depth + 1);

        if (d1 == d2) {
            return {root, d1};
        }

        if (d1 > d2) {
            return {ca1, d1};
        } else {
            return {ca2, d2};
        }
    }
};
