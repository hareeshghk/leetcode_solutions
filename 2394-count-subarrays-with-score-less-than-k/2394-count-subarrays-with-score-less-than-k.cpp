class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long currentSum = 0;
        long long answer = 0;
        int ws = 0;
        for (int we  = 0; we < n; ++we) {
            currentSum += nums[we];

            while (currentSum * (we-ws+1) >= k) {
                currentSum -= nums[ws];
                ws++;
            }
            answer += we-ws+1;
        }
        return answer;
    }
};