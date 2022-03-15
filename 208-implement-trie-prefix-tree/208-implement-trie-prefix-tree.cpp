class Node {
public:
    bool is_last;
    vector<Node*> children;
    Node() {
        children.resize(26, nullptr);
        is_last = false;
    }
};

class Trie {
    Node *head;
public:
    Trie() {
        head = new Node;
        head->is_last = true;
    }
    
    void insert(string word) {
        auto current = head;
        for (int i = 0; i < word.length(); ++i) {
            if (current->children[word[i]-'a'] == nullptr) {
                current->children[word[i]-'a'] = new Node;
            }
            current = current->children[word[i]-'a'];
        }
        current->is_last = true;
    }
    
    bool search(string word) {
        auto current = head;
        for (int i = 0; i < word.length(); ++i) {
            if (current->children[word[i]-'a'] == nullptr) return false;
            current = current->children[word[i]-'a'];
        }
        return current->is_last;
    }
    
    bool startsWith(string prefix) {
        auto current = head;
        for (int i = 0; i < prefix.length(); ++i) {
            if (current->children[prefix[i]-'a'] == nullptr) return false;
            current = current->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */