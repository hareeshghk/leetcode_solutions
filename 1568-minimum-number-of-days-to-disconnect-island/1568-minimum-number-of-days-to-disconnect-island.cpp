#include <vector>

class Solution {
public:
    int countislands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis) {
        if (x<0 || y<0||x>=grid.size()||y>=grid[0].size()|| vis[x][y]||grid[x][y]==0) return;
        
        vis[x][y] = true;
        
        dfs(grid, x+1, y, vis);
        dfs(grid, x, y+1, vis);
        dfs(grid, x, y-1, vis);
        dfs(grid, x-1, y, vis);
    }
    int minDays(vector<vector<int>>& grid) {
        int islands = countislands(grid);
        
        if (islands == 0 || islands > 1) return 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int islands = countislands(grid);
                    grid[i][j] = 1;
                    if (islands == 0 || islands > 1) return 1;
                }
            }
        }
        return 2;
    }
};
