/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serializedstr;
    
    void serialize(TreeNode *root, string &serializedstr) {
        if(root == nullptr) {
            serializedstr += "none,";
            return;
        }
        
        serializedstr += to_string(root->val)+',';
        
        serialize(root->left, serializedstr);
        serialize(root->right, serializedstr);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serializedstr = "";
        serialize(root, serializedstr);
        // cout << serializedstr << endl;
        return serializedstr;
    }

    TreeNode* deserialize(const vector<string> &vals, int &start) {
        if (vals[start] == "none") {
            start++;
            return nullptr;
        }
        
        auto root = new TreeNode(stoi(vals[start]));
        start++;
        root->left = deserialize(vals, start);
        root->right = deserialize(vals, start);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> treevals = split(data);
        int start = 0;
        return deserialize(treevals, start);
    }
    
    vector<string> split(string data) {
        vector<string> result;
        int start = 0;
        for (int end = 0; end < data.length(); ++end) {
            if (data[end] ==',') {
                result.push_back(data.substr(start, end-start));
                start = end + 1;
            }
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));