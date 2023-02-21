class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0, right = nums.length-1;
        int n = nums.length;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if (mid > 0 && nums[mid] == nums[mid-1]) {
                if((n-1-mid) % 2 ==0) {
                    right = mid-2;
                } else {
                    left = mid+1;
                }
            } else if (mid < n-1 && nums[mid]==nums[mid+1]) {
                if (mid%2==0) {
                    left = mid+2;
                } else {
                    right = mid-1;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
}