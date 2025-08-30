#include <algorithm>
#include <vector>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    maxarea = max(maxarea, dfs(i,j,grid,visited));
                }
            }
        }
        return maxarea;
    }
    
    int dfs(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &v) {
        if (i<0||i>=g.size()||j<0|j>=g[0].size()||v[i][j]||g[i][j]==0) return 0;
        v[i][j] = true;
        int result = 1;
        result += dfs(i+1,j,g,v);
        result += dfs(i,j+1,g,v);
        result += dfs(i-1,j,g,v);
        result += dfs(i,j-1,g,v);
        return result;
    }
};
