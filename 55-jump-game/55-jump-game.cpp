class Solution {
public:
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        dp[nums.size()-1] = 1;
        return canjump(nums, 0);
    }
    
    vector<int> dp;
    bool canjump(const vector<int> &nums, int idx) {
        if (idx >= nums.size()) return false;
        
        if (dp[idx] != -1) return (dp[idx]==1)?true:false;
        
        bool result = false;
        
        for (int i = 1; i <= nums[idx]; i++) {
            if (canjump(nums, idx+i)) return true;
        }
        dp[idx] = 0;
        return false;
    }
};