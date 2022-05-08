class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        if (n==3) return nums[0]*nums[1]*nums[2];
        
        sort(nums.begin(), nums.end());
        
        if (nums[n-1] == 0) return 0;
        
        if (nums[n-1] > 0) {
            int val1 = nums[0]*nums[1]*nums[n-1];
            int val2 = nums[n-2]*nums[n-3]*nums[n-1];
            return max(val1, val2);
        }
        
        return nums[n-1]*nums[n-2]*nums[n-3];
    }
};