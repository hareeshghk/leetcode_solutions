class Solution {
    vector<vector<int>> dirs = {{-1,0},{1, 0},{0, 1},{0, -1}};
    unordered_set<int> visited;
    int m, n;
    int currentColour;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        visited.insert(row*n + col);
        currentColour = grid[row][col];
        dfs(grid, row, col, color);
        return grid;
    }
private:
    void dfs(vector<vector<int>> &grid, int x, int y, int c) {
        int neix, neiy;

        bool isBorder = false;

        for (auto& dir : dirs) {
            neix = x+dir[0];
            neiy = y+dir[1];

            if (neix >= 0 && neix < m && neiy >= 0 && neiy < n) {
                if (visited.find(neix*n + neiy) != visited.end()) {
                    continue;
                }

                if (grid[neix][neiy] != currentColour) {
                    isBorder = true;
                    continue;
                }

                visited.insert(neix*n + neiy);
                dfs(grid, neix, neiy, c);
            }
        }
        
        if (x == 0 || x== m-1||y==0||y==n-1) {
            isBorder = true;
        }

        if (isBorder) {
            grid[x][y] = c;
        }
    }
};