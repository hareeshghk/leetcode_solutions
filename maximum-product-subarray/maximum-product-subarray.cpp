class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        int minsofar = nums[0];
        int maxsofar = nums[0];
        int tempmax;
        
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            tempmax = max(maxsofar*nums[i], max(nums[i], minsofar*nums[i]));
            minsofar = min(minsofar*nums[i], min(nums[i], maxsofar*nums[i]));
            maxsofar = tempmax;
            
            if (maxsofar > result) {
                result = maxsofar;
            }
        }
        return result;
    }
};