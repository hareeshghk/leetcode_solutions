#include <iostream>
#include <vector>
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
    vector<vector<int>> result;
    vector<int> curpath;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        getPaths(root, targetSum);
        return result;
    }
    
    void getPaths(TreeNode *root, int target) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (target == root->val) {
                curpath.push_back(root->val);
                result.push_back(curpath);
                curpath.pop_back();
            }
            return;
        }
        curpath.push_back(root->val);
        getPaths(root->left, target-root->val);
        getPaths(root->right, target-root->val);
        curpath.pop_back();
    }
};
