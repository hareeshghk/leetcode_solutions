class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        
        int[][] dp = new int[n][n];
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == s.charAt(i-1)) {
                dp[i-1][i] = 2;
            } else {
                dp[i-1][i] = 1;
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n-len; ++i) {
                dp[i][i+len-1] = Math.max(dp[i+1][i+len-1], dp[i][i+len-2]);
                
                if (s.charAt(i) == s.charAt(i+len-1)) {
                    dp[i][i+len-1] = Math.max(dp[i][i+len-1], dp[i+1][i+len-2] + 2);
                }
            }
        }
        
        return dp[0][n-1];
    }
}