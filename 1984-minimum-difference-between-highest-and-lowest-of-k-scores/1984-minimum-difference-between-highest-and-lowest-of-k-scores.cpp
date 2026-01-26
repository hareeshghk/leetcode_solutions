class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = k-1; i < nums.size(); ++i) {
            minDiff = min(minDiff, nums[i]-nums[i+1-k]);
        }
        return minDiff;
    }
};