class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k-1, right = k+1;
        int result = nums[k];
        int minval = nums[k];
        while (left >=0 && right < nums.size()) {
            if (nums[left] > nums[right]) {
                minval = min(minval, nums[left]);
                left--;
            } else {
                minval = min(minval, nums[right]);
                right++;
            }
            result = max(result, minval * (right-left-1));
        }
        
        while (left >=0) {
            minval = min(minval, nums[left]);
            left--;
            result = max(result, minval * (right-left-1));
        }
        
        while (right < nums.size()) {
            minval = min(minval, nums[right]);
            right++;
            result = max(result, minval * (right-left-1));
        }
        return result;
    }
};