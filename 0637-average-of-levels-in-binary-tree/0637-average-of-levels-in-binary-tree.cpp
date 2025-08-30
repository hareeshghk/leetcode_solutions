#include <iostream>
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
    vector<vector<double>> counter;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        traverse(root, 0);

        vector<double> answer;

        for (auto &c : counter) {
            answer.push_back(c[0] / c[1]);
        }

        return answer;
    }
private:
    void traverse(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (counter.size() == depth) {
            counter.push_back({0, 0});
        }
        counter[depth][0] += root->val;
        counter[depth][1]++;
        traverse(root->left, depth + 1);
        traverse(root->right, depth + 1);
    }
};
