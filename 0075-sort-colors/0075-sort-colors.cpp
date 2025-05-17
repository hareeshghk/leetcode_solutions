class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;

        for (int i = 0; i < n && i <= right;) {
            if (nums[i] == 0) {
                if (i == left) {
                    i++;
                } else {
                    nums[i] = nums[left];
                    nums[left] = 0;
                }
                left++;
            } else if (nums[i] == 2) {
                nums[i] = nums[right];
                nums[right] = 2;
                right--;
            } else {
                i++;
            }
        }
    }
};