class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 0; i <= n;i++) {
            dp[0][i] = 10001;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i*i <= j)
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-i*i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};