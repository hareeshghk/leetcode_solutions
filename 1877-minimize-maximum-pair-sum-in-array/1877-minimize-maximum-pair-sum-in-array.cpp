class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxSum = 0;

        int left = 0, right = nums.size()-1;

        while (left < right) {
            maxSum = max(maxSum, nums[left]+nums[right]);
            left++;
            right--;
        }

        return maxSum;
    }
};