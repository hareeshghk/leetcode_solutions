class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int start = 1;
        int n = nums.size();

        if (nums[start] < nums[0]) return false;

        while (start < n) {
            if (nums[start] < nums[start-1]) {
                break;
            }

            if (nums[start] == nums[start-1]) {
                return false;
            }
            start++;
        }

        if (start == n) return false;

        while (start < n) {
            if (nums[start] > nums[start-1]) {
                break;
            }
            if (nums[start] == nums[start-1]) {
                return false;
            }
            start++;
        }

        if (start == n) return false;

        while (start < n) {
            if (nums[start] <= nums[start-1]) {
                return false;
            }
            start++;
        }
        return true;
    }
};