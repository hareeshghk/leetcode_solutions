class Solution {
public:
    vector<vector<int>> grid;
    int N;
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        
        this->grid = grid;
        dp.resize(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        return max(0, findmaxcherrys(0,0,0));
    }
    
    vector<vector<vector<int>>> dp;
    int findmaxcherrys(int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        
        if (r1 == N || r2==N || c1==N || c2==N || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -99999;
        
        if (r1 == N-1 && c1 == N-1) return grid[r1][c1];
        
        if (dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];
        
        int curval = grid[r1][c1];
        if (c1 != c2) curval += grid[r2][c2];
        dp[r1][c1][c2] = curval + max(findmaxcherrys(r1+1, c1, c2), max(findmaxcherrys(r1, c1+1, c2),max(findmaxcherrys(r1, c1+1, c2+1), findmaxcherrys(r1+1, c1, c2+1))));
        return dp[r1][c1][c2];
    }
};