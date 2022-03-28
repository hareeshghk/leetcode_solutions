class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<int> dp(n, 1), temp(n,1);

        for (int i = 1; i < m; i++) {
            temp = dp;
            for (int j = 1; j < n; j++) {
                dp[j] = temp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};