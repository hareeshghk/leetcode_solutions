class Solution {
    vector<unordered_map<int, int>> dp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dp(i, t) = dp[i-1, t-nums[i]] + dp[i-1, t+nums[i]]
        dp = vector<unordered_map<int, int>>(nums.size());
        return getNumWays(nums, nums.size()-1, target);
    }
private:
    int getNumWays(vector<int> &nums, int i, int t) {
        if (i < 0) {
            return t==0;
        }

        if (dp[i].find(t) != dp[i].end()) return dp[i][t];

        return dp[i][t] = getNumWays(nums, i-1, t+nums[i]) + getNumWays(nums, i-1, t-nums[i]);
    }
};