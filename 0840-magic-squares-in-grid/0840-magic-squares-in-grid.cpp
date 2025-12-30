class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int answer = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        for (int row = 2; row < rows; ++row) {
            for (int column = 2; column < columns; ++column) {
                if (isMagical(grid, row-2, column-2)) answer++;
            }
        }
        return answer;
    }
private:
    inline bool isMagical(vector<vector<int>>& grid, int startx, int starty) {
        cout << startx << " " << starty << endl;

        int maxNumber = -1, minNumber = 16;
        set<int> s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                maxNumber = max(maxNumber, grid[startx+i][starty+j]);
                minNumber = min(minNumber, grid[startx+i][starty+j]);
                s.insert(grid[startx+i][starty+j]);
            }
        }

        if (minNumber != 1 || maxNumber != 9 || s.size() != 9) return false;

        int firstRowSum = grid[startx][starty] + grid[startx][starty+1] + grid[startx][starty+2];
        int firstColumnSum = grid[startx][starty] + grid[startx+1][starty] + grid[startx+2][starty];

        if (firstRowSum != firstColumnSum) return false;

        for (int i = 1; i < 3; ++i) {
            if (grid[startx+i][starty] + grid[startx+i][starty+1] + grid[startx+i][starty+2] != firstRowSum) return false;

            if (grid[startx][starty+i] + grid[startx+1][starty+i] + grid[startx+2][starty+i] != firstColumnSum) return false;
        }

        if (grid[startx][starty] + grid[startx+1][starty+1] + grid[startx+2][starty+2] != firstRowSum) return false;

        if (grid[startx][starty+2] + grid[startx+1][starty+1] + grid[startx+2][starty] != firstRowSum) return false;

        return true;
    }
};