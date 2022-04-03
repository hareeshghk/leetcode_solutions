class Solution {
public:
    int m,n;
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        this->m = m;
        this->n = n;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string curpath;
        unordered_set<string> seen;
        int result = 0;
        for (int i = 0; i < m;++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    curpath = dfs(grid, i, j, visited);
                    // cout << curpath << endl;
                    if (seen.count(curpath) == 0){
                        ++result;
                        seen.insert(curpath);
                    }
                }
            }
        }
        return result;
    }
    
    string dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        visited[i][j] = true;
        string curpath = "";
        int x,y;
        // down
        x = i+1;
        y = j;
        if (x < m && grid[x][y] == 1 && !visited[x][y]) {
            curpath += "D"+dfs(grid, x, y, visited)+",";
        }
        // right
        x = i;
        y = j+1;
        if (y < n && grid[x][y] == 1 && !visited[x][y]) {
            curpath += "R"+dfs(grid, x, y, visited)+",";
        }
        // up
        x = i-1;
        y = j;
        if (x >= 0 && grid[x][y] == 1 && !visited[x][y]) {
            curpath += "U"+dfs(grid, x, y, visited)+",";
        }
        // left
        x = i;
        y = j-1;
        if (y >=0 && grid[x][y] == 1 && !visited[x][y]) {
            curpath += "L"+dfs(grid, x, y, visited)+",";
        }
        return curpath;
    }
};