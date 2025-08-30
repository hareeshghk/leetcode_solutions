#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int count1=0, count2=0, left, right;
        // using two condtion either even indexes smaller or odd indexes smaller.
        // marked boundaries as 1001 so left wall and right wall always satifies our case.
        for (int i = 0; i < nums.size(); i++) {
            left = (i-1)>=0?nums[i-1]:1001;
            right = (i == nums.size()-1)?1001:nums[i+1];
            
            if (i&1) {
                count1 += max(0, nums[i] - min(left, right) + 1);
            } else {
                count2 += max(0, nums[i] - min(left, right) + 1);
            }
        }
        return min(count1, count2);
    }
};
