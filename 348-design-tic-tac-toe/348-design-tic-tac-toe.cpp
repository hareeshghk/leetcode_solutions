#include <vector>
using namespace std;

class TicTacToe {
    vector<vector<int>> players_row_count;
    vector<vector<int>> players_column_count;
    vector<vector<int>> players_diagonal_count;
    int size;
public:
    TicTacToe(int n) {
        players_row_count.resize(n, vector<int>(2,0));
        players_column_count.resize(n, vector<int>(2,0));
        players_diagonal_count.resize(2, vector<int>(2,0));
        size = n;
    }
    
    int move(int row, int col, int player) {
        players_row_count[row][player-1]++;
        if (players_row_count[row][player-1] == size) return player;
        players_column_count[col][player-1]++;
        if (players_column_count[col][player-1] == size) return player;
        if (row == col) {
            players_diagonal_count[0][player-1]++;
            if (players_diagonal_count[0][player-1] == size) return player;
        }
        
        if(row == size-1-col) {
            players_diagonal_count[1][player-1]++;
            if (players_diagonal_count[1][player-1] == size) return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
