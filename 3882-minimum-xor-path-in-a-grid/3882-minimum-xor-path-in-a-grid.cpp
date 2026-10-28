class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector<vector<unordered_set<int>>>(m, vector<unordered_set<int>>(n));

        dp[0][0].insert(grid[0][0]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (j > 0) {
                    for (auto val : dp[i][j-1]) {
                        dp[i][j].insert(val^grid[i][j]);
                    }
                }

                if (i > 0) {
                    for (auto val : dp[i-1][j]) {
                        dp[i][j].insert(val^grid[i][j]);
                    }
                }
            }
        }

        int minxor = 1024;
        for (auto val : dp[m-1][n-1]) {
            minxor = min(minxor, val);
        }

        return minxor;
    }
};