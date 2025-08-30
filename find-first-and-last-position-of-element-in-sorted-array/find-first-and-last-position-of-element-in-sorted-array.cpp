#include <vector>

class Solution {
public:
    int target_;
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        target_ = target;
        int nums_len = nums.size();
        ans.push_back(Bound(nums, 0, nums_len-1, true));
        ans.push_back(Bound(nums, 0, nums_len-1, false));
        return ans;
    }
    int Bound(vector<int> &n, int left, int right, bool lowerBound) {
        int bound = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (n[mid] < target_) {
                left = mid+1;
            } else if (n[mid] > target_) {
                right = mid-1;
            } else {
                bound = mid;
                if (lowerBound) right = mid-1;
                else left = mid+1;
            }
        }
        return bound;
    }
};
