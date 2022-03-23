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
    string curs, curd, ans;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        curs = "";
        curd = "";
        ans = "";
        findNodes(root, startValue, destValue);
        return ans;
    }
    
    pair<bool,bool> findNodes(TreeNode *root, int s, int d) {
        if (root == nullptr) return make_pair(false, false);
        
        pair<bool,bool> result(false, false), cur(false, false);
        
        if (root->val == s) cur.first = true;
        if (root->val == d) cur.second = true;
        
        pair<bool,bool> l = findNodes(root->left, s, d);
        if (l.first == true && l.second == true) return l;
        pair<bool,bool> r = findNodes(root->right, s, d);
        if (r.first == true && r.second == true) return r;
        
        if (l.first == true) curs+='L';
        if(l.second == true) curd+='L';
        
        if (r.first == true) curs+='R';
        if(r.second == true) curd+='R';
        
        if ((l.first && r.second)||(l.second && r.first)) {
            reverse(curd.begin(), curd.end());
            ans.resize(curs.length(), 'U');
            ans += curd;
        }
        
        if ((cur.first && l.second) || (cur.first && r.second)){
            reverse(curd.begin(), curd.end());
            ans = curd;
        }
        
        if ((cur.second && l.first) || (cur.second && r.first)){
            ans.resize(curs.length(), 'U');
        }
        
        result.first = cur.first || l.first||r.first;
        result.second = cur.second || l.second||r.second;
        return result;
    }
};