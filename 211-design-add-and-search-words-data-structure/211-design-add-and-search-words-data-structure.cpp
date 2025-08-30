#include <string>
#include <vector>
using namespace std;

class Node {
    bool is_end;
public:
    vector<Node*> children;
    Node() {
        children.resize(26, nullptr);
        is_end = false;
    }
    
    void setend() {
        is_end = true;
    }
    
    bool isend() {
        return is_end;
    }
    
    bool contains(char ch) {
        return (children[ch-'a'] != nullptr);
    }
    
    void setchar(char ch) {
        children[ch-'a'] = new Node;
    }
    
    Node* getchar(char ch) {
        return children[ch-'a'];
    }
};
class WordDictionary {
    Node *head;
public:
    WordDictionary() {
        head = new Node;
        head->setend();
    }
    
    void addWord(string word) {
        auto current = head;
        
        for (int i = 0; i < word.length(); ++i) {
            if (!current->contains(word[i])) {
                current->setchar(word[i]);
            }
            current = current->getchar(word[i]);
        }
        current->setend();
    }
    
    bool search(string word) {
        return search(word, 0, head);
    }
    
    bool search(string &word, int idx, Node *root) {
        if (root == nullptr) return false;
        
        if (idx == word.length()) return root->isend();
        
        if (word[idx] != '.') return search(word, idx+1, root->getchar(word[idx]));
        
        for (int i = 0; i < 26; i++) {
            if (search(word, idx+1, root->getchar('a'+i))) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
