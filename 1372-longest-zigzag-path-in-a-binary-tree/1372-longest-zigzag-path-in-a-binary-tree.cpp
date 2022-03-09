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
    int ans;
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        ans = 0;
        ans = max(ans, longestZigZag(root, true));
        ans = max(ans, longestZigZag(root, false));
        return ans-1;
    }
    
    int longestZigZag(TreeNode *root, bool isleft) {
        if (root == nullptr) return 0;
        
        int lefth = longestZigZag(root->left, true);
        int righth = longestZigZag(root->right, false);
        
        ans = max(ans, max(lefth, righth)+1);
        
        if (isleft) {
            return 1 + righth;
        } else {
            return 1 + lefth;
        }
    }
};