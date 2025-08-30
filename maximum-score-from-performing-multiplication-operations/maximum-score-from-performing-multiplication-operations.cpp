#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        int right;
        for (int i = m-1; i>=0;i--) {
            for (int left = i;left>=0;left--) {
                right = n-1 -(i-left);
                dp[i][left] = max(nums[left]*multipliers[i]+dp[i+1][left+1], nums[right]*multipliers[i]+dp[i+1][left]);
            }
        }
        return dp[0][0];
    }
};
