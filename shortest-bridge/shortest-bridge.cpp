#include <queue>
#include <vector>

class Solution {
public:
    int m,n;
    int shortestBridge(vector<vector<int>>& grid) {
        queue<int> firstIsland;
        
        m = grid.size();
        n = grid[0].size();
        bool done = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i,j,grid, firstIsland);
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        int level = 0;
        
        while (!firstIsland.empty()) {
            int levelSize = firstIsland.size();
            for (int i = 0 ; i < levelSize; ++i) {
                auto cur = firstIsland.front();
                firstIsland.pop();
                
                int x, y;
                x = cur / n;
                y = cur % n;
                
                if (x-1 >= 0) {
                    if (grid[x-1][y] == 0) {
                        grid[x-1][y] = -1;
                        firstIsland.push((x-1)*n+y);
                    } else if (grid[x-1][y] == 1) {
                        return level;
                    }
                }
                if (y-1 >= 0) {
                    if (grid[x][y-1] == 0) {
                        grid[x][y-1] = -1;
                        firstIsland.push((x)*n+y-1);
                    } else if (grid[x][y-1] == 1) {
                        return level;
                    }
                }
                if (x+1 < m) {
                    if (grid[x+1][y] == 0) {
                        grid[x+1][y] = -1;
                        firstIsland.push((x+1)*n+y);
                    } else if (grid[x+1][y] == 1) {
                        return level;
                    }
                }
                if (y+1 < n) {
                    if (grid[x][y+1] == 0) {
                        grid[x][y+1] = -1;
                        firstIsland.push((x)*n+y+1);
                    } else if (grid[x][y+1] == 1) {
                        return level;
                    }
                }
            }
            ++level;
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return -1;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid, queue<int> &firstIsland) {
        if (x < 0 || x >= m || y < 0 || y>=n || grid[x][y] == 0 || grid[x][y] == -1) return;
        // cout << "cordinates" << x << " " << y << endl;
        firstIsland.push(x*n+y);
        grid[x][y] = -1;
        dfs(x+1, y, grid, firstIsland);
        dfs(x, y+1, grid, firstIsland);
        dfs(x, y-1, grid, firstIsland);
        dfs(x-1, y, grid, firstIsland);
    }
};
