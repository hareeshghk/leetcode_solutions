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
        
        int next = idx+1;
        while (next < days.length) {
            if (days[next] >= days[idx]+7) break;
            next++;
        }
        cost = Math.min(cost, costs[1]+minCost(days, next, costs));
        
        while (next < days.length) {
            if (days[next] >= days[idx]+30) break;
            next++;
        }
        cost = Math.min(cost, costs[2]+minCost(days, next, costs));
        dp[idx] = cost;
        return cost;
    }
    
    private int getNextIndex(int[] days, int low, int high, int value) {
        int mid;
        
        if (high >= days.length) {
            high = days.length-1;
        }
        
        while (low < high) {
            mid = low + (high - low)/2;
            
            if (days[mid] <= value) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        
        return high;
    }
}