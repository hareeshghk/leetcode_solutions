class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // changing the problem
        // equal subset sum means we need to make a subset with wholesum/2.
        // if above is possible then true, otherwise false.

        int totalSum = 0;
        for (auto num : nums) {
            totalSum += num;
        }

        if (totalSum & 1) return false;

        int neededSum = totalSum/2;

        // dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-nums[i]]
        // can make following as two vectors.
        int n = nums.size();
        vector<bool> dp = vector<bool>(neededSum + 1, false);
        if (nums[0] <= neededSum) dp[nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            vector<bool> dp2 = vector<bool>(neededSum + 1, false);
            for (int j = 0; j <= neededSum; ++j) {
                dp2[j] = dp[j] || ((j-nums[i])>=0?dp[j-nums[i]]:false);
            }
            dp = dp2;
            if (dp[neededSum] == true) return true;
        }
        return false;
    }
};