#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_len = nums.size();
        
        if (nums_len == 0) {
            return 0;
        }
        
        if (nums_len == 1) {
            return nums[0];
        }
        
        vector<int> dp(nums_len);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int house = 2; house < nums_len; ++house) {
            dp[house] = max(nums[house] + dp[house-2], dp[house-1]);
        }
        
        return dp[nums_len - 1];
    }
};
