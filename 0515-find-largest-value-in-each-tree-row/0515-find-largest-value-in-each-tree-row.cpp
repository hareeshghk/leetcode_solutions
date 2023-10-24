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
        map<int, int> maxValuePerDepth;
        
        dfs(root, 0, maxValuePerDepth);
        
        for_each(maxValuePerDepth.begin(), maxValuePerDepth.end(), [&answer](const pair<int,int> &p) {
            answer.push_back(p.second);
        });
        return answer;
    }
    
    void dfs(TreeNode *root, int depth, map<int,int> &m) {
        if (root == nullptr) return;
        
        if (m.find(depth) == m.end()) {
            m[depth] = root->val;
        } else {
            m[depth] = max(m[depth], root->val);
        }
        dfs(root->left, depth + 1, m);
        dfs(root->right, depth + 1, m);
    }
};