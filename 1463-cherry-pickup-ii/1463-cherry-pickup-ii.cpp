#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    int rows, cols;
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        rows = grid.size(); // min 2 rows and cols so no need of base cases.
        cols = grid[0].size();
        dp.resize(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return findMaxCherries(0, 0, cols-1);
    }
    
    vector<int> dirs{-1,0,1};
    vector<vector<vector<int>>> dp;
    int findMaxCherries(int t, int c1, int c2) {
        if (t == rows) return 0;
        
        if (dp[t][c1][c2] != -1) return dp[t][c1][c2];
        
        int result = grid[t][c1];
        
        if (c1 != c2) result += grid[t][c2];
        
        int next_y1, next_y2;
        int maxval = 0;
        for (int i = 0; i<3;i++) {
            next_y1 = dirs[i]+c1;
            if (next_y1 <0 || next_y1 >=cols) continue;
            for (int j=0; j<3;j++) {
                next_y2 = dirs[j]+c2;
                if (next_y2 <0 || next_y2 >=cols) continue;
                maxval = max(maxval, findMaxCherries(t+1, next_y1, next_y2));
            }
        }
        dp[t][c1][c2] = result+maxval;
        return result+maxval;
    }
};
