#include <vector>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n ;i++) {
            if (nums[i] > 0 && nums[i] < n && nums[i] != i+1) {
                if (nums[i] == nums[nums[i]-1]) continue;
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
