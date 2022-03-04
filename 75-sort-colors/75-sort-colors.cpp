class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        
        for (auto num : nums) {
            if (num ==0) zero++;
            else if(num==1) one++;
            else two++;
        }
        
        int oneidx = zero, left =0, right= nums.size()-1;
        
        int i = 0;
        while (i < zero) {
            if (nums[i] == 0) {
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
            } else {
                swap(nums[i], nums[oneidx]);
                oneidx++;
            }
        }
        
        i = zero;
        while (i < zero+one) {
            if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[right]);
                --right;
            }
        }
        return;
    }
};