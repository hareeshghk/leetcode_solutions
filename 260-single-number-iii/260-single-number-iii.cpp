#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalxor = 0;
        for (auto num : nums) totalxor ^=  num;
        
        //find first bit with is not zero in totalxor
        int mask = 1;
        while (totalxor != 0) {
            if(totalxor & 1) {
                break;
            }
            totalxor /=2;
            mask <<= 1;
        }
        int val1 = 0, val2 = 0;
        for (auto num : nums) {
            if (num &mask) val1 ^= num;
            else val2 ^= num;
        }
        return {val1, val2};
    }
};
