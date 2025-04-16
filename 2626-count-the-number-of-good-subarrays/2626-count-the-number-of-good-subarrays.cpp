/*
at every index we calculate number of subarrays satisfyuing k condition
at every index create a map and counr k pairs by going back, at any index if pairs become k then remaing left indices can be added or not to become subarrrays.
time will be O(N ^ 2)
space is O(N ^ 2)

n * (n-1)/2 -n-1*n-2/2 = n-1
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        long long answer = 0;
        int ws = 0;
        unordered_map<int, int> numCount;
        long long currentWindowsCount = 0;
        for (int we = 0; we < n; ++we) {
            currentWindowsCount += numCount[nums[we]];
            numCount[nums[we]]++;

            while (ws <= we) {
                long long newCount = currentWindowsCount - (numCount[nums[ws]]-1);
                if (newCount >= k) {
                    currentWindowsCount -= (numCount[nums[ws]]-1);
                    numCount[nums[ws]]--;
                    ws++;
                } else {
                    break;
                }
            }

            if (currentWindowsCount >= k) {
                answer += ws+1;
            }

        }
        return answer;
    }
};