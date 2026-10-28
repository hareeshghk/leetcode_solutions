class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 1024; ++k) {
                    if (j > 0 && dp[i][j-1][k]) {
                        dp[i][j][grid[i][j] ^ k] = true;
                    }

                    if (i > 0 && dp[i-1][j][k]) {
                        dp[i][j][grid[i][j] ^ k] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 1024; ++i) {
            if (dp[m-1][n-1][i]) return i;
        }

        return -1;
    }
};