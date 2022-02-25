class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int nums_len = nums.size();
        vector<int> leftmaxarr(nums_len, 0);
        vector<int> rightminarr(nums_len, 0);
        
        leftmaxarr[0] = nums[0];
        rightminarr[nums_len-1] = nums[nums_len-1];
        for (int i = 1; i < nums_len; ++i) {
            leftmaxarr[i] = max(nums[i], leftmaxarr[i-1]);
            rightminarr[nums_len-1-i] = min(nums[nums_len-1-i], rightminarr[nums_len-i]);
        }
        
        int ans = 0;
        for (int i = 1; i < nums_len-1; ++i) {
            if (leftmaxarr[i-1] < nums[i] && nums[i] < rightminarr[i+1]) {
                ans += 2;
            } else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};