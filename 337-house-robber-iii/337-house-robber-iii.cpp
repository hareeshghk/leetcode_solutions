#include <algorithm>
#include <iostream>
#include <utility>
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
    int rob(TreeNode* root) {
        int a,b;
        tie(a,b) = robb(root);
        return max(a,b);
    }
    
    pair<int,int> robb(TreeNode* root) {
        if (root == nullptr) return make_pair(0,0);
        
        int v1 = root->val;
        int x1,x2,y1,y2;
        tie(x1,y1) = robb(root->left);
        tie(x2,y2) = robb(root->right);
        return make_pair(v1+y1+y2, max(x1,y1)+max(x2,y2));
    }
};
