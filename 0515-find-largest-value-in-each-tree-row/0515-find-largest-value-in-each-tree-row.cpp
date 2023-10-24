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
    vector<int> largestValues(TreeNode* root) {
        vector<int> answer;
        
        if (root == nullptr) return answer;
        
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
                
        while(!bfsQueue.empty()) {
            int currentLevelQueueSize = bfsQueue.size();
            int maxValue = INT_MIN;
            
            while (currentLevelQueueSize--) {
                TreeNode* node = bfsQueue.front();
                bfsQueue.pop();
                
                maxValue = max(maxValue, node->val);
                
                if (node->left != nullptr) {
                    bfsQueue.push(node->left);
                }
                
                if (node->right != nullptr) {
                    bfsQueue.push(node->right);
                }
            }
            
            answer.push_back(maxValue);
        }
        return answer;
    }
};