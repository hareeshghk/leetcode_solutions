#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int curnum = nums[0];
        for (int i = 1; i < n; i++) {
            if (curnum == 0) return false;
            curnum = max(curnum-1, nums[i]);
        }
        return true;
    }
    
//     vector<int> dp;
//     bool canjump(const vector<int> &nums, int idx) {
//         if (idx >= nums.size()) return false;
        
//         if (dp[idx] != -1) return (dp[idx]==1)?true:false;
        
//         bool result = false;
        
//         for (int i = 1; i <= nums[idx]; i++) {
//             if (canjump(nums, idx+i)) return true;
//         }
//         dp[idx] = 0;
//         return false;
//     }
};
