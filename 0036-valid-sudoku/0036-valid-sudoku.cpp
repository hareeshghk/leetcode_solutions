#include <vector>
using namespace std;

class Solution {
    vector<vector<char>> _b;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        _b = board;
        // check rows
        for (int i = 0; i < 9; ++i) {
            if (!isValidRow(i)) return false;
        }

        // check columns
        for (int i = 0; i < 9; ++i) {
            if (!isValidColumn(i)) return false;
        }

        // check boxes
        for (int i = 0; i < 9; ++i) {
            if (!isValidBox(i)) return false;
        }

        return true;
    }
private:
    // Validates if a row in sudoku board is valid
    bool isValidRow(int i) {
        vector<bool> seen(9, false);
        for (int j = 0; j < 9; ++j) {
            if (_b[i][j] != '.') {
                int num = _b[i][j] - '1';
                if (seen[num]) return false;
                seen[num] = true;
            }
        }
        return true;
    }

    // Validates if a column in sudoku board is valid
    bool isValidColumn(int j) {
        vector<bool> seen(9, false);
        for (int i = 0; i < 9; ++i) {
            if (_b[i][j] != '.') {
                int num = _b[i][j] - '1';
                if (seen[num]) return false;
                seen[num] = true;
            }
        }
        return true;
    }

    // Validates if a box in sudoku board is valid
    bool isValidBox(int boxIndex) {
        vector<bool> seen(9, false);
        int startRow = (boxIndex / 3) * 3;
        int startCol = (boxIndex % 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c = _b[startRow + i][startCol + j];
                if (c != '.') {
                    int num = c - '1';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }
        return true;
    }
};
