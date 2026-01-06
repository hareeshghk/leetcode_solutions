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
    int maxLevelSum(TreeNode* root) {
        int maxLevelSum = INT_MIN;
        int currentLevel = 0, answer = 1;
        queue<TreeNode*> bfsQ;
        bfsQ.push(root);

        while (!bfsQ.empty()) {
            currentLevel++;
            int currentSize = bfsQ.size();
            int currentLevelSum = 0;
            while (currentSize--) {
                auto node = bfsQ.front();
                bfsQ.pop();
                currentLevelSum += node->val;

                if (node->left != nullptr) {
                    bfsQ.push(node->left);
                }

                if (node->right != nullptr) {
                    bfsQ.push(node->right);
                }
            }

            if (currentLevelSum > maxLevelSum) {
                maxLevelSum = currentLevelSum;
                answer = currentLevel;
            }
        }
        return answer;
    }
};