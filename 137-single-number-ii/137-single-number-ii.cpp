#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int count, mask = 1;
        for (int i = 0; i < 32; i++) {
            mask = 1<<(31-i);
            count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] & mask) count++;
            }
            if (count % 3 != 0) {
                result = result | mask;
            }
        }
        return result;
    }
};
