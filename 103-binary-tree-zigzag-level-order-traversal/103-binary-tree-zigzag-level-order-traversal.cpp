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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        deque<TreeNode*> dq1, dq2;
        bool reverse = false;
        dq1.push_back(root);
        while (!dq1.empty()) {
            int n = dq1.size();
            vector<int> currow;
            for (int i = 0; i < n; i++) {
                if (reverse) {
                    auto cur = dq1.back();
                    dq1.pop_back();
                    currow.push_back(cur->val);
                    if (cur->right != nullptr) dq2.push_front(cur->right);
                    if (cur->left != nullptr) dq2.push_front(cur->left);
                } else {
                    auto cur = dq1.front();
                    dq1.pop_front();
                    currow.push_back(cur->val);
                    if (cur->left != nullptr) dq2.push_back(cur->left);
                    if (cur->right != nullptr) dq2.push_back(cur->right);
                }
            }
            dq1=dq2;
            dq2.clear();
            reverse = !reverse;
            result.push_back(currow);
        }
        return result;
    }
};