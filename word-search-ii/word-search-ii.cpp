#include <string>
#include <vector>

class TrieNode {
public:
    string word;
    vector<TrieNode*> children;
    TrieNode() {
        children.resize(26, nullptr);
        word = "";
    }  
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        auto current = root;
        for (int i = 0; i < word.length(); i++) {
            if (current->children[word[i]-'a'] == nullptr) {
                current->children[word[i]-'a'] = new TrieNode;
            }
            current = current->children[word[i]-'a'];
        }
        current->word = word;
    }
};

class Solution {
    Trie *head;
    int m,n;
    vector<string> result;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new Trie;
        
        m = board.size();
        n = board[0].size();
        
        for (auto word : words) {
            head->insert(word);
        }
        
        TrieNode *root = head->root;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->children[board[i][j]-'a'] != nullptr) {
                    backtrack(board, i, j, root);
                }
            }
        }
        
        return result;
    }
    
    void backtrack(vector<vector<char>> &board, int x, int y, TrieNode *root) {
        char letter = board[x][y];
        auto curnode = root->children[board[x][y]-'a'];
        
        if (curnode->word != "") {
            result.push_back(curnode->word);
            curnode->word = "";
        }

        board[x][y] = '#';
        
        if (x+1 < m && board[x+1][y] != '#' && curnode->children[board[x+1][y]-'a'] != nullptr) backtrack(board,x+1, y, curnode);
        if (x-1 >=0 && board[x-1][y] != '#' && curnode->children[board[x-1][y]-'a'] != nullptr) backtrack(board,x-1, y, curnode);
        if (y+1 < n && board[x][y+1] != '#' && curnode->children[board[x][y+1]-'a'] != nullptr) backtrack(board,x, y+1, curnode);
        if (y-1 >=0 && board[x][y-1] != '#' && curnode->children[board[x][y-1]-'a'] != nullptr) backtrack(board,x, y-1, curnode);
            
        board[x][y] = letter;
        return;
    }
    
    bool NoNext(vector<vector<char>> &board, int x, int y) {
        if (x+1 < m && board[x+1][y] != '#') return false;
        if (x-1 >= 0 && board[x-1][y] != '#') return false;
        if (y+1 < n && board[x][y+1] != '#') return false;
        if (y-1 >=0 && board[x][y-1] != '#') return false;
        return true;
    }
};
