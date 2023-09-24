class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] dp = new double[query_row+1][query_row+1];
        
        dp[0][0] = poured;
        
        for (int i = 1; i <= query_row; ++i) {
            Arrays.fill(dp[i], 0.0);
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = Math.max(0.0, (dp[i-1][j]-1)/2) + Math.max(0.0, (j==0?0:(dp[i-1][j-1]-1)/2));
            }
        }
        
        return Math.min(1.0, dp[query_row][query_glass]);
    }
}