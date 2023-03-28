class Solution {
    int[] dp;
    public int mincostTickets(int[] days, int[] costs) {
        dp = new int[days.length];
        
        for (int i = 0; i < days.length; ++i) {
            dp[i] = -1;
        }
        return minCost(days, 0, costs);
    }
    
    private int minCost(int[] days, int idx, int[] costs) {
        if (idx >= days.length) return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int cost = Integer.MAX_VALUE;
        
        cost = Math.min(cost, costs[0] + minCost(days, idx+1, costs));
        
        // This also can be done by using a binary search to find index for value >= days[idx]+6 in idx+1 to idx+8 range;
        // I am finding next index whose value is >= days[idx]+7
        int next = idx+1;
        while (next < days.length) {
            if (days[next] >= days[idx]+7) break;
            next++;
        }
        cost = Math.min(cost, costs[1]+minCost(days, next, costs));
        
        // This also can be done by using a binary search to find index for value >= days[idx]+30 in idx+1 to idx+31 range;
        // I am finding next index whose value is >= days[idx]+7
        while (next < days.length) {
            if (days[next] >= days[idx]+30) break;
            next++;
        }
        cost = Math.min(cost, costs[2]+minCost(days, next, costs));
        dp[idx] = cost;
        return cost;
    }
}