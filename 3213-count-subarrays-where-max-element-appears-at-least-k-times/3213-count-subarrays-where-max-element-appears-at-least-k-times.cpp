#include <algorithm>
#include <vector>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxNum = nums[0];
        for (int i = 1; i < n; ++i) {
            maxNum = max(maxNum, nums[i]);
        }

        int maxNumCount = 0;

        int ws = 0;
        long long answer = 0;
        for (int we = 0; we < n; ++we) {
            if (nums[we] == maxNum) maxNumCount++;

            if (nums[ws] != maxNum) ws++; 

            while (ws <= we && (maxNumCount > k || (maxNumCount == k && nums[ws] != maxNum))) {
                if (nums[ws] == maxNum) {
                    maxNumCount--;
                }
                ws++;
            }

            if (maxNumCount >= k) {
                answer +=(ws + 1);
            }
        }
        return answer;
    }
};
