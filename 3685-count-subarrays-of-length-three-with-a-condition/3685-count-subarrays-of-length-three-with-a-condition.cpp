#include <vector>

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();

        int answer = 0;

        for (int i = 2; i < n; ++i) {
            if (2*(nums[i-2] + nums[i]) == nums[i-1]) ++answer;
        }
        return answer;
    }
};
