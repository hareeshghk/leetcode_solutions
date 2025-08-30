#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_set<char>> row_map,column_map,block_map;
        for (int i = 0; i < n; i++) {
            row_map[i] = unordered_set<char>();
            column_map[i] = unordered_set<char>();
            block_map[i] = unordered_set<char>();
        }
        
        int row,col,block;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                row = i;
                col = j;
                block = ((i/3)*3)+(j/3);
                
                // check row
                if (row_map[row].find(board[i][j]) != row_map[row].end()) return false;
                row_map[row].insert(board[i][j]);
                
                // check column
                if (column_map[col].find(board[i][j]) != column_map[col].end()) return false;
                column_map[col].insert(board[i][j]);
                
                // check block
                if (block_map[block].find(board[i][j]) != block_map[block].end()) return false;
                block_map[block].insert(board[i][j]);
            }
        }
        return true;
    }
};
