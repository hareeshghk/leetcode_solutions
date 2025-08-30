#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> store(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'E') {
                    fillStore(store, grid, i, j);
                }
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result = max(result, store[i][j]);
            }
        }
        return result;
    }
    
    void fillStore(vector<vector<int>> &store, vector<vector<char>> &grid, int i, int j) {
        // store[i][j]++;
        int left = j-1, right = j+1, up = i-1, down = i+1;
        
        while (left >=0 && grid[i][left] != 'W') {
            if (grid[i][left] != 'E') store[i][left]++;
            --left;
        }
        
        while (right < store[0].size() && grid[i][right] != 'W') {
            if (grid[i][right] != 'E')store[i][right]++;
            ++right;
        }
        
        while (up >=0 && grid[up][j] != 'W') {
            if (grid[up][j] != 'E') store[up][j]++;
            --up;
        }
        
        while (down < store.size() && grid[down][j] != 'W') {
            if (grid[down][j] != 'E') store[down][j]++;
            ++down;
        }
    }
};
