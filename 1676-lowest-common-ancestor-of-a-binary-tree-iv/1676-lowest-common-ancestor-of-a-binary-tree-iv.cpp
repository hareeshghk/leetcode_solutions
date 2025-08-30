#include <iostream>
#include <unordered_set>
#include <vector>

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
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        result = nullptr;
        unordered_set<TreeNode*> nodesmap;
        for (auto node : nodes) {
            nodesmap.insert(node);
        }
        findNodes(root, nodesmap);
        return result;
    }
    
    int findNodes(TreeNode* root, const unordered_set<TreeNode*> &nodesmap) {
        if (root == nullptr) return 0;
        
        int curval = 0;
        if (nodesmap.count(root) != 0) ++curval;
        
        int leftval = findNodes(root->left, nodesmap);
        int rightval = findNodes(root->right, nodesmap);
        
        if (curval + leftval+rightval == nodesmap.size()) {
            if (curval == 0) {
                if (leftval != 0 && rightval !=0) result = root;
            } else if (curval != 0) {
                result = root;
            }
        }
        return curval + leftval+rightval;
    }
};
