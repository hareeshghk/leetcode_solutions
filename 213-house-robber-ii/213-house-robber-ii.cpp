class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        
        if (n == 1) return nums[0];
        
        if (n == 2) return max(nums[0], nums[1]);
        
        // if (n==3) return max(nums[0], max(nums[1], nums[2]));
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for (int i = 2; i < n-1; i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        int result = dp[n-2];
        
        dp.clear();
        
        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n-1; i++) {
            dp[i] = max(nums[(i+1) % n]+dp[i-2], dp[i-1]);
        }
        
        return max(result, dp[n-2]);
    }
};