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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return subRoot == nullptr;
        
        bool result = false;
        if (root->val == subRoot->val) {
            result = isMatched(root, subRoot);
        }
        return result || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isMatched(TreeNode* root, TreeNode *s) {
        if (s==nullptr) return root==nullptr;
        if (root==nullptr) return s==nullptr;
        
        if (root->val != s->val) return false;
        
        return isMatched(root->left, s->left) && isMatched(root->right, s->right);
    }
};
