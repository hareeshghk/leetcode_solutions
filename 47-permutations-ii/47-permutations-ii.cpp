class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0);
        return result;
    }
    
    void permute(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        set<int> seen;
        for (int i = idx; i < nums.size(); ++i) {
            if (seen.count(nums[i]) == 0) {
                seen.insert(nums[i]);
                swap(nums[idx], nums[i]);
                permute(nums, idx+1);
                swap(nums[idx], nums[i]);
            }
        }
    }
};