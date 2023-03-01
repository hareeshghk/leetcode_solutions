class Solution {
    int[] temp;
    public int[] sortArray(int[] nums) {
        if (nums.length == 0) return nums;
        
        temp = new int[nums.length];
        MergeSort(nums, 0, nums.length-1);
        return nums;
    }
    
    void MergeSort(int[] nums, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right-left)/2;
        
        MergeSort(nums, left, mid);
        MergeSort(nums, mid+1, right);
        Merge(nums, left, mid, right);
    }
    
    void Merge(int[] nums, int left, int mid, int right) {
        int itr1 = left, itr2 = mid+1;
        int counter = 0;
        while (itr1 <= mid && itr2 <= right) {
            if (nums[itr1] <= nums[itr2]) {
                temp[counter++] = nums[itr1++];
            } else {
                temp[counter++] = nums[itr2++];
            }
        }
        
        while (itr1 <= mid) {
            temp[counter++] = nums[itr1++];
        }
        
        while (itr2 <= right) {
            temp[counter++] = nums[itr2++];
        }
        
        counter = 0;
        for (itr1 = left; itr1 <= right; ++itr1) {
            nums[itr1] = temp[counter++];
        }
    }
    
}