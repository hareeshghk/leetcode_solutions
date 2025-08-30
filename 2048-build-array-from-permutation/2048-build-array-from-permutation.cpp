#include <vector>

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> answer = vector<int>(nums.size());
        int ctr = 0;
        for (auto num : nums) {
            answer[ctr++] = nums[num];
        }
        return answer;
    }
};
