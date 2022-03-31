class Solution {
public:
    vector<int> prefixsums;
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        prefixsums.resize(n,0);
        prefixsums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsums[i] = prefixsums[i-1]+nums[i];
        }
        dp.resize(m+1, vector<int>(n, -1));
        return findminofmaxsum(nums, m, 0, n);
    }
    vector<vector<int>> dp;
    int findminofmaxsum(vector<int> &nums, int m, int idx, int n) {
        if (dp[m][idx] != -1) return dp[m][idx];
        if (m == 1) {
            return getsum(n, idx);
        }
        int cursum = 0;
        int minval = INT_MAX;
        for (int i = idx; i <= n-m; ++i) {
            cursum = cursum+nums[i];
            minval = min(minval, max(cursum, findminofmaxsum(nums, m-1, i+1, n)));
            if (cursum > minval) break;
        }
        dp[m][idx] = minval;
        return minval;
    }
    
    int getsum(int n, int idx) {
        return prefixsums[n-1]-(idx-1>=0?prefixsums[idx-1]:0);
    }
};