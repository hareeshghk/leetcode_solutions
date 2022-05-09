class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target) return true;
            
            if(nums[mid] == nums[left]) {
                left++;
                continue;
            }
            
            bool pivotarray = existsinfirst(nums, left, nums[mid]);
            bool targetarray = existsinfirst(nums, left, target);
            
            if (pivotarray ^ targetarray) {
                if (pivotarray) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if (target < nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return false;
    }
    
    bool existsinfirst(vector<int> &nums, int start, int ele) {
        return nums[start] <= ele;
    }
};