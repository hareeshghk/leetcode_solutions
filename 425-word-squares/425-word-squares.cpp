#include <string>
#include <vector>
using namespace std;

class Node {
public:
    vector<Node*> children;
    vector<int> wordIndices;
    Node() {
        children.resize(26, nullptr);
        wordIndices.resize(0);
    }
    
    void addChild(Node *node, int num, int wordIdx) {
        children[num] = node;
        wordIndices.push_back(wordIdx);
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void addWord(const string &word, int idx) {
        auto curroot = root;
        
        for (auto ch : word) {
            if (curroot->children[ch-'a'] == nullptr) {
                curroot->children[ch-'a'] = new Node();
            }
            curroot = curroot->children[ch-'a'];
            curroot->wordIndices.push_back(idx);
        }
    }
    
    vector<int> ListWordIds(const string &prefix) {
        auto curroot = root;
        
        for (auto ch : prefix) {
            if (curroot->children[ch-'a'] == nullptr) {
                return {};
            }
            curroot = curroot->children[ch-'a'];
        }
        
        return curroot->wordIndices;
    }
};

class Solution {
public:
    Trie *trie;
    vector<vector<string>> result;
    vector<int> current;
    vector<string> words;
    vector<vector<string>> wordSquares(vector<string>& wos) {
        
        this->words = wos;
        int n = words.size();
        
        int word_len = words[0].length();
        
        trie = new Trie();
        
        for (int i = 0; i < n; ++i) {
            trie->addWord(words[i], i);
        }
        
        for (int i = 0; i < n; ++i) {
            current.push_back(i);
            backtrack(1, word_len);
            current.pop_back();
        }
        
        return result;
    }
    
    void backtrack(int cur_num_words, int target_num_words) {
        if (cur_num_words == target_num_words) {
            vector<string> curresult;
            for (auto idx : current) {
                curresult.push_back(words[idx]);
            }
            result.push_back(curresult);
            return;
        }
        
        string prefix = GetNextPrefix(cur_num_words);
        
        for (auto child : trie->ListWordIds(prefix)) {
            current.push_back(child);
            backtrack(cur_num_words+1, target_num_words);
            current.pop_back();
        }
    }
    
    string GetNextPrefix( int num_words) {
        string prefix = "";
        
        for (int i = 0; i < num_words; ++i) {
            prefix += words[current[i]][num_words];
        }
        return prefix;
    }
};
