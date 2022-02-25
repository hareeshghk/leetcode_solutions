class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(n,-100000)));
        
        // dp[0/1][j][i] says at about max profit at the end of ith day and done j buyings and left with holding or not holding.
        
        // Initialization.
        dp[0][0][0] = 0;
        dp[1][1][0] = -prices[0];
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j < n;++j) {
                dp[0][i][j] = max(dp[1][i][j-1]+prices[j], dp[0][i][j-1]);
                if (i > 0)
                    dp[1][i][j] = max(dp[0][i-1][j-1]-prices[j], dp[1][i][j-1]);
            }
        }
        
        // we need value which says after nth day you are not holding any.
        return max(dp[0][2][n-1], max(dp[0][1][n-1], dp[0][0][n-1]));
    }
};