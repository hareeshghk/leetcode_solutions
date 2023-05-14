class Solution {
    int[] dp;
    public int maxScore(int[] nums) {
        int numsLen = nums.length;
        int n = numsLen/2;
        
        // dp with remaining integers and turn as key. since n is <=7 we use bit map to store remainign integers.
        
        dp = new int[1<<numsLen];
        Arrays.fill(dp, -1);
        
        return GetMax(nums, 0, 0, n);
    }
    
    private int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    
    private int GetMax(int[] nums, int pairsVisited, int visited, int n) {
        if (pairsVisited == n) {
            return 0;
        }
        
        if (dp[visited] != -1) {
            return dp[visited];
        }
        
        int maxVal = 0;
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (((visited & (1<<i)) != 0) || ((visited & (1<<j)) != 0)) {
                    continue;
                }
                
                int curSum = (pairsVisited + 1)*gcd(nums[i], nums[j]);
                int remainingSum = GetMax(nums, pairsVisited + 1, visited | ((1<<i) | (1<<j)), n);
                
                maxVal = Math.max(maxVal, curSum + remainingSum);
            }
        }
        
        dp[visited] = maxVal;
        return maxVal;
    }
}