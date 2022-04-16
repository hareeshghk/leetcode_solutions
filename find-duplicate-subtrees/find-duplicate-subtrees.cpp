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
    unordered_map<string,TreeNode*> duplicates;
    unordered_set<string> seen;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string leftSubtree = getSubTree(root->left);
        string rightSubtree = getSubTree(root->right);
        string tree = leftSubtree + to_string(root->val) + rightSubtree;
        if (seen.find(tree) != seen.end()) {
            if (duplicates.find(tree)==duplicates.end()) {
                duplicates[tree] = root;
            }
        } else {
            seen.insert(tree);
        }
        
        vector<TreeNode*> duplicateRoots;
        
        for (auto d : duplicates) {
            duplicateRoots.push_back(d.second);
        }
        return duplicateRoots;
    }
    
    string getSubTree(TreeNode *root) {
        if (root == nullptr) {
            return "n";
        }
        
        string leftSubtree = getSubTree(root->left);
        string rightSubtree = getSubTree(root->right);
        string tree = leftSubtree +"L" + to_string(root->val) + "M" + rightSubtree + "R";
        if (seen.find(tree) != seen.end()) {
            if (duplicates.find(tree) == duplicates.end()) {
                duplicates[tree] = root;
            }
        } else {
            seen.insert(tree);
        }
        return tree;
    }
};