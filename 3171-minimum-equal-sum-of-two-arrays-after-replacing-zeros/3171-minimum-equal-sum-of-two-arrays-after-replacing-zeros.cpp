#include <algorithm>
#include <vector>

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (auto num : nums1) {
            sum1 += num;
            if (num == 0) z1++;
        }

        for (auto num : nums2) {
            sum2 += num;
            if (num == 0) z2++;
        }

        if (sum1 == sum2) {
            if (z1 != 0 && z2 != 0) {
                return sum1 + max(z1,z2);
            }

            if (z1==0 && z2 == 0) return sum1;

            return -1;
        }

        if (z1 != 0 && z2 != 0) {
            return max(sum1+z1, sum2+z2);
        }

        if (z1 == 0 && z2 == 0) {
            return -1;
        }

        if (z1 == 0) {
            if (sum2 > sum1) return -1;

            if (sum2 + z2 <= sum1) return sum1;
            return -1;
        }

        if (z2 == 0) {
            if (sum1 > sum2) return -1;
            if (sum1+z1 <= sum2) return sum2;
            return -1;
        }

        return -1;
    }
};
