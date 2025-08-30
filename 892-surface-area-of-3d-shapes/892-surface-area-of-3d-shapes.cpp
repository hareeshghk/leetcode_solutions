#include <algorithm>
#include <vector>

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i<m ;i++) {
            for (int j =0; j< n; j++) {
                //left
                if (j==0) {
                    ans += grid[i][j];
                } else {
                    ans += max(grid[i][j]-grid[i][j-1], 0);
                }
                //right
                if (j==n-1) {
                    ans += grid[i][j];
                } else {
                    ans += max(grid[i][j]-grid[i][j+1], 0);
                }
                //top
                if (i==0) {
                    ans += grid[i][j];
                } else {
                    ans += max(grid[i][j]-grid[i-1][j], 0);
                }
                //bottom
                if (i==m-1) {
                    ans += grid[i][j];
                } else {
                    ans += max(grid[i][j]-grid[i+1][j], 0);
                }
                if (grid[i][j] > 0) ans += 2;
            }
        }
        return ans;
    }
};
