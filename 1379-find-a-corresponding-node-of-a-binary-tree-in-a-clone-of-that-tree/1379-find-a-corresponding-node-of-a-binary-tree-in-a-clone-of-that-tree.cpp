#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *result;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        result = nullptr;
        
        Traverse(original, cloned, target);
        return result;
    }
    
    bool Traverse(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) return false;
        
        if (original == target) {
            result = cloned;
            return true;
        }
        
        bool foundleft = Traverse(original->left, cloned->left, target);
        
        if (foundleft) return true;
        
        return Traverse(original->right, cloned->right, target);
    }
};
