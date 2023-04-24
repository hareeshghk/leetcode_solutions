class Solution {
    int[][] dp;
    public int minInsertions(String s) {
        int n = s.length();
        dp = new int[n][n];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        return minInsertions(s, 0, n-1);
    }
    
    int minInsertions(String s, int start, int end) {
        if (end-start+1 <= 1) {
            return 0;
        }
        
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        
        int answer;
        if (s.charAt(start) == s.charAt(end)) {
            answer = minInsertions(s, start+1, end-1);
        } else {
            answer = Math.min(minInsertions(s, start, end-1), minInsertions(s, start+1, end))+1;
        }
        dp[start][end] = answer;
        return answer;
    }
}