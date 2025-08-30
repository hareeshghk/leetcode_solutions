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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return root;
        
        if (root->left == nullptr && root->right == nullptr) return root;
        
        TreeNode* prevRoot = nullptr;
        TreeNode* leftchild, *rightchild, *tl, *tr;
        
        leftchild = root;
        rightchild = nullptr;
        
        
        while (leftchild != nullptr) {
            tl = leftchild->left;
            tr = leftchild->right;
            
            leftchild->right = prevRoot;
            leftchild->left = rightchild;
            prevRoot = leftchild;
            
            leftchild = tl;
            rightchild = tr;
        }
        
        return prevRoot;
    }
};
