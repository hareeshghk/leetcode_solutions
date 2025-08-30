#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    string word;
    int m,n,k;
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        m = board.size();
        n = board[0].size();
        k = word.length();
        
        if (k == 0) return true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ispossible(0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool ispossible(int curidx, int x, int y) {
        if (curidx == k) return true;
        
        if (x < 0 || x >=m || y <0 || y>=n || board[x][y] != word[curidx]) return false;
        
        board[x][y] = '#';
        
        int nextx, nexty;
        
        if (ispossible(curidx+1, x + 1, y) || ispossible(curidx+1, x-1, y) || ispossible(curidx+1, x, y+1)||ispossible(curidx+1, x, y-1)) return true;
        board[x][y] = word[curidx];
        return false;
    }
};
