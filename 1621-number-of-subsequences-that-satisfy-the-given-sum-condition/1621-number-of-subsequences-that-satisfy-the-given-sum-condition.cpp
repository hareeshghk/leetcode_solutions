#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mod = 1000000007;

        vector<int> powers = vector<int>(n, 0);
        powers[0] = 1;
        for (int i = 1; i < n; ++i) {
            powers[i] = (powers[i-1] * 2) % mod;
        }

        int left = 0, right = n-1;
        int answer = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer = (answer + powers[right-left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
};
