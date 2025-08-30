#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        long long int maxwidth = 1;
        
        typedef pair<TreeNode*, long long int> cell;
        
        queue<cell> bfs_q;
        bfs_q.push(cell(root,0));
        
        while (!bfs_q.empty()) {
            int cursize = bfs_q.size();
            long long int low = bfs_q.front().second;
            long long int high;
            cell curroot;
            for (int i = 0; i < cursize; ++i) {
                curroot = bfs_q.front();
                bfs_q.pop();
                
                if(curroot.first->left != nullptr) {
                    bfs_q.push(cell(curroot.first->left, (2*(curroot.second-low))));
                }
                if(curroot.first->right != nullptr) {
                    bfs_q.push(cell(curroot.first->right, (2*(curroot.second-low)+1)));
                }
            }
            high = curroot.second;
            maxwidth = max(maxwidth, high-low+1);
        }
        return maxwidth;
    }
};
