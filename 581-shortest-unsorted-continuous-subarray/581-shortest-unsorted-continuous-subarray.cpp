#include <algorithm>
#include <vector>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int leftAscIdx = 0, rightDscIdx = n-1;
        
        int minofremaining = nums[n-1];
        int maxofremaining = nums[0];
        
        while (leftAscIdx+1 < n) {
            maxofremaining = max(maxofremaining, nums[leftAscIdx]);
            if (nums[leftAscIdx] <= nums[leftAscIdx+1]) {
                leftAscIdx++;
            } else break;
        }
        
        // if sorted already
        if (leftAscIdx == n-1) {
            return 0;
        }
        
        while (rightDscIdx-1 >= 0) {
            minofremaining = min(minofremaining, nums[rightDscIdx]);
            if (nums[rightDscIdx] >= nums[rightDscIdx-1]) {
                rightDscIdx--;
            } else break;
        }
        
        if (rightDscIdx == 0) return n;
        
        // cout << leftAscIdx << endl;
        // cout << rightDscIdx << endl;
        
        
        for (int i = leftAscIdx+1; i < rightDscIdx; ++i) {
            minofremaining = min(minofremaining, nums[i]);
            maxofremaining = max(maxofremaining, nums[i]);
        }
        
        // cout << minofremaining << endl;
        // cout << maxofremaining << endl;
        
        int left = upper_bound(nums.begin(), nums.begin()+leftAscIdx, minofremaining)-nums.begin();
        int right = lower_bound(nums.begin()+rightDscIdx, nums.end(), maxofremaining)-nums.begin();
        
        // cout << left << " " << right << endl;
        
        return right-left;
    }
};
