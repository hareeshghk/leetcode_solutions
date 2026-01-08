class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1));
        
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < m; ++i) {
            firstMax = max(firstMax, nums1[i]);
            firstMin = min(firstMin, nums1[i]);
        }

        for (int i = 0; i < n; ++i) {
            secondMax = max(secondMax, nums2[i]);
            secondMin = min(secondMin, nums2[i]);
        }

        if (firstMax < 0 && secondMin > 0) return firstMax * secondMin;

        if (firstMin > 0 && secondMax < 0) return firstMin * secondMax;

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                dp[i][j] = max(dp[i+1][j], max(dp[i][j+1], (nums1[i] * nums2[j]) + dp[i+1][j+1]));
            }
        }
        return dp[0][0];
    }
};