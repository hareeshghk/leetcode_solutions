#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xcount = 0;
        int ocount = 0;
        

        for (int i = 0; i<3;i++) {
            for (int j=0;j<3;j++) {
                if (board[i][j] == 'X') xcount++;
                else if (board[i][j] == 'O') ocount++;
            }
        }
        
        if (xcount-ocount != 0 && xcount-ocount != 1) return false;
        
        bool xwin = check(board, 'X');
        bool owin = check(board, 'O');
        
        if (xwin && owin) return false;
        
        if (xwin) {
            return (xcount-ocount == 1);
        }
        if (owin) {
            return (xcount == ocount);
        }
        
        return true;
    }
    
    bool check(vector<string> &s, char sign) {
        bool rowdone=true, coldone=true;
        
        for (int row = 0; row < 3; ++row) {
            rowdone = true; coldone = true;
            for (int col = 0; col < 3; ++col) {
                if (s[row][col] != sign) rowdone = false;
                if (s[col][row] != sign) coldone = false;
            }
            if (rowdone || coldone) return true;
        }
        
        // check diagonals;
        bool diagdone = true;
        bool revdiagdone = true;
        for (int row = 0; row < 3; ++row) {
            if (s[row][row] != sign) diagdone = false;
            if (s[row][2-row] != sign) revdiagdone = false;
        }
        
        return (diagdone || revdiagdone);
    }
};
