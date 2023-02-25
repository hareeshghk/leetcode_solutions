class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        
        int maxTillNow = prices[n-1];
        int profit = 0;
        
        for (int i = n-2; i >=0; --i) {
            profit = Math.max(profit, maxTillNow-prices[i]);
            maxTillNow = Math.max(maxTillNow, prices[i]);
        }
        return profit;
    }
}