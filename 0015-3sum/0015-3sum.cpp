class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            int remaining = -1 * nums[i];
            int left = i+1;
            int right = n-1;

            while (left < right) {
                if (nums[left] + nums[right] < remaining) {
                    left++;
                } else if(nums[left] + nums[right] > remaining) {
                    right--;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left + 1 < n && nums[left] == nums[left+1]) left++;
                    while (right-1 >= 0 && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }

            while (i+1 < n && nums[i] == nums[i+1])  i++;
        }

        return ans;
    }
};