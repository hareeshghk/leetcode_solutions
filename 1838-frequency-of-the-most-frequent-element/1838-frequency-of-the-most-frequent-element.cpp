#include <algorithm>
#include <vector>

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long ws = 0;
        int result = 1;
        long long curwindowsum = 0;
        for (long long we = 0; we < nums.size(); ++we) {
            curwindowsum += nums[we];
            while (ws <=we && nums[we]*(we-ws+1) > curwindowsum+k) {
                curwindowsum -= nums[ws];
                ws++;
            }
            if ((we-ws+1)> result){
                result = we-ws+1;
            }
        }
        return result;
    }
};
