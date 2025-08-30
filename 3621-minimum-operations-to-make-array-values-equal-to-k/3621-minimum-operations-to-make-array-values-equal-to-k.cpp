#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minelement = nums[0];
        vector<bool> exists = vector<bool>(101, false);
        int distinctCount = 0;
        for (auto num :nums) {
            minelement = min(minelement, num);
            if (!exists[num]) {
                distinctCount++;
                exists[num] = true;
            }
        }

        if (minelement < k) return -1;
        if (minelement == k) return distinctCount-1;
        return distinctCount;
    }
};
