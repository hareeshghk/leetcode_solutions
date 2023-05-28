class Solution {
    int[][] dp;
    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int len = cuts.length;
        dp = new int[len][len];
        return minCost(cuts, 0, n, 0, len-1);
    }
    
    private int minCost(int[] cuts, int left, int right, int start, int end) {
        if (start > end) {
            return 0;
        }
        
        if (start == end) {
            return right-left;
        }
        
        if (dp[start][end] != 0) return dp[start][end];
        
        int cost = Integer.MAX_VALUE;
        for (int i = start; i <= end; ++i) {
            cost = Math.min(cost, (right-left) + minCost(cuts, left, cuts[i], start, i-1) + minCost(cuts, cuts[i], right, i + 1, end));
        }
        
        return dp[start][end] = cost;
    }
}