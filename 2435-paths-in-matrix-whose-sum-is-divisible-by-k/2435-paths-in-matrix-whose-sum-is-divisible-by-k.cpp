class Solution {
    vector<vector<vector<int>>> dp;
    int m,n;
    int mod = 1000000007;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return getPaths(grid, m-1, n-1, k, 0);
    }
private:
    long long int getPaths(vector<vector<int>> &grid, int x, int y, int k, int rem) {
        if (x < 0 || y < 0) return 0;

        if (x == 0 && y == 0) {
            if (grid[0][0]%k == rem) return 1;
            return 0;
        }

        if (dp[x][y][rem] != -1) return dp[x][y][rem]; 

        int nextrem = (k + rem - (grid[x][y]%k))%k;

        long long int a = getPaths(grid, x-1, y, k, nextrem);
        long long int b = getPaths(grid, x, y-1, k, nextrem);
        dp[x][y][rem] = (a+b)%mod;
        return dp[x][y][rem];
    }
};