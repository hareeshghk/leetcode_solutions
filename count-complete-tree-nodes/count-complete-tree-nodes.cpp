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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Get height
        int height = GetHeight(root);
        
        // binary serach if a node present on not from 2^h to 2^h+1-1
        // result of binary search is answer
        // During binary search use numbers bit to take left or right direction
        int left = (1<<height), right = (1<<(height+1))-1;
        
        int result = left;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nodeExists(root, mid, height)) {
                result = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return result;
    }
    
    int GetHeight(TreeNode *root) {
        int h = 0;
        while (root != nullptr) {
            root = root->left;
            ++h;
        }
        return h-1;
    }
    
    bool nodeExists(TreeNode *root, int val, int curheight) {
        if (root == nullptr) return false;
        
        if (curheight==0) return true;
        
        if ((val & (1<<(curheight-1))) == 0) {
            return nodeExists(root->left, val, curheight-1);
        } else {
            return nodeExists(root->right, val, curheight-1);
        }
    }
};