#include <algorithm>
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

typedef struct node {
    bool is_bst;
    int lower;
    int upper;
    int numnodes;
    node(bool val) {
        is_bst = val;
        lower = INT_MIN;
        upper = INT_MAX;
        numnodes = 0;
    }
    
    node(bool val, int l, int u) {
        is_bst = val;
        lower = l;
        upper = u;
        numnodes = 0;
    }
};

class Solution {
public:
    int result;
    int largestBSTSubtree(TreeNode* root) {
        result = 0;
        
        IsBst(root);
        
        return result;
    }
    
    node IsBst(TreeNode *root) {
        if (root == nullptr) {
            return node(true);
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            auto temp = node(true, root->val, root->val);
            temp.numnodes = 1;
            result = max(result, 1);
            // cout << result << " " << root->val << endl;
            return temp;
        } else if (root->left == nullptr) {
            auto temp = IsBst(root->right);
            if (!temp.is_bst) return temp;
            if (root->val >= temp.lower) {
                temp.is_bst = false;
                return temp;
            }
            
            temp.lower = root->val;
            temp.numnodes+=1;
            result = max(result, temp.numnodes);
            // cout << result << " " << root->val << endl;
            return temp;
        } else if (root->right == nullptr) {
            auto temp = IsBst(root->left);
            if (!temp.is_bst) return temp;
            if (root->val <= temp.upper) {
                temp.is_bst = false;
                return temp;
            }
            
            temp.upper = root->val;
            temp.numnodes +=1;
            result = max(result, temp.numnodes);
            // cout << result << " " << root->val << endl;
            return temp;
        } else {
            auto left = IsBst(root->left);
            auto right = IsBst(root->right);
            
            if (!left.is_bst || !right.is_bst) return node(false);
            
            if (root->val <= left.upper || root->val >= right.lower || left.upper >= right.lower) {
                return node(false);
            }
            
            auto temp = node(true, left.lower, right.upper);
            temp.numnodes = left.numnodes+right.numnodes+1;
            result = max(result, temp.numnodes);
            // cout << result << " " << root->val << endl;
            return temp;
        }
    }
};
