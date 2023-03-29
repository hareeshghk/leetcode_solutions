class Solution {
    int[][] dp;
    public int maxSatisfaction(int[] sat) {
        Arrays.sort(sat);
        int n = sat.length;
        
        dp = new int[n][];
        
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[n+1];
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1;
            }
        }
        
        return Math.max(maxS(sat, 0, 1), 0);
    }
    
    private int maxS(int[] s, int index, int pos) {
        if (index >= s.length) {
            return 0;
        }
        
        if (dp[index][pos] != -1) return dp[index][pos];
        
        int val = Integer.MIN_VALUE;
        
        val = Math.max(val, s[index]*pos + maxS(s, index+1, pos+1));
        val = Math.max(val, maxS(s, index+1, pos));
        
        dp[index][pos] = val;
        return val;
    }
}