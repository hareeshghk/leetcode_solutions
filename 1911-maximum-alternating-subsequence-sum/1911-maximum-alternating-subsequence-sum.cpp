class Solution {
public:
    vector<int> nums;
    int n;
    long long maxAlternatingSum(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        dp.resize(n, vector<long long int>(2, -1));
        return maxAlternatingSum(0, true);
    }
    
    vector<vector<long long int>> dp;
    long long maxAlternatingSum(int idx, bool iseven) {
        if (idx == n) return 0;
        
        if (dp[idx][iseven] != -1) return dp[idx][iseven];
        long long val = maxAlternatingSum(idx+1, iseven);
        
        if (iseven) {
            val = max(val, nums[idx] + maxAlternatingSum(idx+1, !iseven));
        } else {
            val = max(val, -nums[idx] + maxAlternatingSum(idx+1, !iseven));
        }
        return dp[idx][iseven] = val;
    }
};