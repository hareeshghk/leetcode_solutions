#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    vector<unordered_map<char, bool>> rowmap;
    vector<unordered_map<char, bool>> colmap;
    vector<unordered_map<char, bool>> blockmap;
public:
    void solveSudoku(vector<vector<char>>& board) {
        int board_len = board.size();
        // rowmap.resize(board_len, unordered_map<char, bool>{});
        // colmap.resize(board_len, unordered_map<char, bool>{});
        // colmap.resize(board_len, unordered_map<char, bool>{});
        unordered_map<char, bool> default_map {{'1',false},{'2',false},{'3',false},{'4',false},{'5',false},{'6',false},{'7',false},{'8',false},{'9',false}};
        for(int i = 0; i < board_len; ++i) {
            rowmap.push_back(default_map);
            colmap.push_back(default_map);
            blockmap.push_back(default_map);
        }
        
        for(int i = 0; i < board_len; ++i) {
            for (int j = 0; j < board_len; ++j) {
                if (board[i][j] != '.') {
                    rowmap[i][board[i][j]] = true;
                    colmap[j][board[i][j]] = true;
                    blockmap[3*(i/3)+(j/3)][board[i][j]] = true;
                }
            }
        }
        
        solvesudoku(board, 0, 0);
        return;
    }
    
    bool solvesudoku(vector<vector<char>> &board, int i, int j) {
        if (i == 9 && j == 0) {
            return true;
        }
        if (board[i][j] != '.') {
            if (j == 8) return solvesudoku(board, i+1, 0);
            else return solvesudoku(board, i, j+1);
        }
        bool val = false;
        for (int k = 1; k <= 9; k++) {
            if (rowmap[i]['0'+ k] == false  && colmap[j]['0'+ k] == false &&
               blockmap[3*(i/3)+(j/3)]['0'+k] == false) {
                board[i][j] = '0'+k;
                rowmap[i]['0'+ k] = true;
                colmap[j]['0'+ k] = true;
               blockmap[3*(i/3)+(j/3)]['0'+k] = true;
                if (j == 8) val = solvesudoku(board, i+1, 0);
                else val = solvesudoku(board, i, j+1);
                if (val) return true;
                
                board[i][j] = '.';
                rowmap[i]['0'+ k] = false;
                colmap[j]['0'+ k] = false;
                blockmap[3*(i/3)+(j/3)]['0'+k] = false;
            }
        }
        return false;
    }
};
