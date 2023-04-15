class Solution {
    int n;
    int[][] dp;
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        n = piles.size();
        dp = new int[n][k+1];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = -1;
            }
        }
        
        // cummulate sum of lists
        for (List<Integer> pile : piles) {
            int m = pile.size();
            
            for (int i = 1; i < m; ++i) {
                pile.set(i, pile.get(i)+ pile.get(i-1));
            }
        }
        
        // max(DP(x, k'))
        return MaxSum(piles, 0, k);
    }
    
    int MaxSum(List<List<Integer>> piles, int index, int k) {
        if (k == 0) {
            return 0;
        }
        
        final List<Integer> pile = piles.get(index);
        
        if (index == n-1) {
            int x = pile.size();
            if (x < k) {
                return -1;
            }
            return pile.get(k-1);
        }
        
        if (dp[index][k] != -1) {
            return dp[index][k];
        }
        
        int answer = -1;
        
        for (int i = 0; i <= Math.min(k, pile.size()); ++i) {
            answer = Math.max(answer, (i==0?0:pile.get(i-1)) + MaxSum(piles, index+1, k-i));
        }
        dp[index][k] = answer;
        return answer;
    }
}