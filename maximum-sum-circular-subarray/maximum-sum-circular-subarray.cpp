#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int cursum = 0;
        int maxsumkadane = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            cursum = max(cursum+nums[i], nums[i]);
            maxsumkadane = max(maxsumkadane, cursum);
        }
        
        // for circular part we can prefix of array and suffix of array.
        // for every suffix we need to know maxprefix so that we can combine with cur suffix.
        vector<int> maxprefixarray(n, 0);
        maxprefixarray[0] = nums[0];
        cursum = nums[0];
        for (int i = 1; i < n; i++) {
            cursum += nums[i];
            maxprefixarray[i] = max(cursum, maxprefixarray[i-1]);
        }
        
        cursum = 0;
        int right = n-1;
        while (right > 0) {
            cursum += nums[right];
            maxsumkadane = max(maxsumkadane, cursum+maxprefixarray[right-1]);
            --right;
        }
        return maxsumkadane;
    }
};
