/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    int value;
    int start;
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        
        string result = "";
        
        while (!q.empty()) {
            int levelsize = q.size();
            for (int i = 0; i < levelsize; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == nullptr) {
                    result += "N,";
                    continue;
                }
                
                result += to_string(cur->val)+",";
                for (auto child : cur->children) {
                    q.push(child);
                }
                q.push(nullptr);
            }
            // result += "N,";
        }
        // cout << result << endl;
        return result;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return nullptr;
        queue<Node*> q;
        start = 0;
        getValue(data);
        Node* root = new Node(value);
        q.push(root);
        start += 2;
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto curchilds = getChildVals(data);
            for (auto child : curchilds) {
                auto childNode = new Node(child);
                cur->children.push_back(childNode);
                q.push(childNode);
            }
        }
        return root;
    }
    
    int getValue(string &d) {
        int j = start;
        while (d[start] != ',') {
            start++;
        }
        value = stoi(d.substr(j, start-j));
        start++;
        return value;
    }
    
    vector<int> getChildVals(string &d) {
        vector<int> vals;
        while (d[start] != 'N') {
            getValue(d);
            vals.push_back(value);
        }
        start+=2;
        return vals;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));