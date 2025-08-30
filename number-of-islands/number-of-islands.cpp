#include <vector>

class Solution {
public:
    vector<bool> visited;
    int m, n;
    vector<vector<char>> grid;
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        visited.resize(m*n, false);
        int ans = 0;
        for (int i =0; i <m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i*n+j] && grid[i][j]=='1') {
                    ans++;
                    dfs(i*n+j);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int pos) {
        int x = pos/n;
        int y = pos%n;
        visited[pos] = true;
        
        int nextx, nexty, nextpos;
        for (auto dir : dirs) {
            nextx = x+dir[0];
            nexty = y+dir[1];
            if (nextx <0 || nextx >=m||nexty <0||nexty>=n) continue;
            nextpos = nextx*n+nexty;
            if (!visited[nextpos] && grid[nextx][nexty]=='1') dfs(nextpos);
        }
    }
};
