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
        findNodes(root, nodes);
        return result;
    }
    
    int findNodes(TreeNode* root, vector<TreeNode*> &nodes) {
        if (root == nullptr) return 0;
        
        int curval = 0;
        for (auto node : nodes) {
            if (node == root) {
                curval++;
                break;
            }
        }
        
        int leftval = findNodes(root->left, nodes);
        int rightval = findNodes(root->right, nodes);
        
        if (curval + leftval+rightval == nodes.size()) {
            if (curval == 0) {
                if (leftval != 0 && rightval !=0) result = root;
            } else if (curval != 0) {
                result = root;
            }
        }
        return curval + leftval+rightval;
    }
};