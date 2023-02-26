class Solution {
    int[][] dp;
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        dp = new int[m][];
        
        for (int i = 0; i < m; ++i) {
            dp[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        
        return minDistance(word1, 0, word2, 0);
    }
    
    int minDistance(String w1, int idx1, String w2, int idx2) {
        if (idx1 == w1.length() || idx2 == w2.length()) {
            if (idx1 == w1.length()) return w2.length()-idx2;
            if (idx2 == w2.length()) return w1.length()-idx1;
        }
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int result = Integer.MAX_VALUE;
        
        if (w1.charAt(idx1) == w2.charAt(idx2)) {
            result = minDistance(w1, idx1+1, w2, idx2+1);
        } else {
            result = Math.min(1+minDistance(w1, idx1+1, w2, idx2), Math.min(1+minDistance(w1, idx1, w2, idx2+1), 1+minDistance(w1, idx1+1, w2, idx2+1)));
        }
        dp[idx1][idx2] = result;
        return result;
    }
}