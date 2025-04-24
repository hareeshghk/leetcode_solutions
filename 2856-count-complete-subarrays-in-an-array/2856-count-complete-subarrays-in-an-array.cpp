class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // iterate through the nums at every index assume that is end of subarray and calculate number of subarrays.
        unordered_set<int> distinct;
        for (auto num : nums) {
            distinct.insert(num);
        }

        int distinctElements = distinct.size();
        int ws = 0;
        unordered_map<int, int> counter;
        int answer = 0;
        for (int we = 0; we < nums.size(); ++we) {
            counter[nums[we]]++;
            while (ws <= we && counter[nums[ws]] > 1) {
                counter[nums[ws]]--;
                ws++;
            }
            if (counter.size() == distinctElements) {
                answer += ws+1;
            }
        }
        return answer;
    }
};