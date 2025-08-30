#include <vector>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for (auto num : nums) {
            totalSum += num;
        }
        
        // if total sum odd then its not possible to divide
        if (totalSum & 1) return false;
        
        int neededSum = totalSum/2;
        
        return isSubsetSumPossible(nums, neededSum);
    }
    
    bool isSubsetSumPossible(vector<int> &nums, int target) {
        int n = nums.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        
        // initialization
        for (int i = 0; i <=target; ++i) {
            dp[0][i] = false;
        }
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j-nums[i-1] >= 0) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};
