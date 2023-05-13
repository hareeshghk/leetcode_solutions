class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        int[] dp = new int[high+1];
        int mod = 1000000007;
        dp[zero] = 1;
        dp[one] += 1;
        
        int answer = 0;
        for (int i = 0; i <= high; ++i) {
            if (i >= zero) dp[i] += dp[i-zero];
            
            if(i >= one) dp[i] += dp[i-one];
            
            dp[i] %= mod;
            
            if (i >= low) {
                answer = (answer + dp[i])%mod;
            }
        }
        return answer;
    }
}