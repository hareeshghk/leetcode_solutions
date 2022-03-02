/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> chosenpath1;
    vector<TreeNode*> chosenpath2;
    vector<TreeNode*> candidates;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool found = dfs(root, p);
        chosenpath2 = chosenpath1;
        chosenpath1.clear();
        candidates.clear();
        found = dfs(root, q);
        int i = 0;
        while (i < chosenpath1.size() && i < chosenpath2.size()) {
            if (chosenpath1[i] != chosenpath2[i]) return chosenpath1[i-1];
            i++;
        }
        if (i == chosenpath1.size()) return chosenpath1[i-1];
        else if(i == chosenpath2.size()) return chosenpath2[i-1];
        return nullptr;
    }
    
    bool dfs(TreeNode *root, TreeNode* p) {
        if (root == nullptr) return false;
        if (root == p) {
            candidates.push_back(root);
            chosenpath1 = candidates;
            return true;
        }
        candidates.push_back(root);
        bool f;
        f = dfs(root->left, p);
        if (f) return f;
        f = dfs(root->right, p);
        if (f) return f;
        candidates.pop_back();
        return false;
    }
};