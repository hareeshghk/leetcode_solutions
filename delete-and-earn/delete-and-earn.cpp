#include <algorithm>
#include <vector>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int nums_len = nums.size();
        vector<int> counter(200001, 0);
        
        int maxnum = 0;
        for (auto num : nums) {
            counter[num]++;
            maxnum = max(maxnum, num);
        }
        
        vector<int> dp(maxnum+1,0);
        dp[0] = counter[0];
        dp[1] = counter[1];
        for (int i = 2; i <= maxnum; i++) {
            dp[i] = max(dp[i-2]+(counter[i]*i), dp[i-1]);
        }
        return dp[maxnum];
    }
};
