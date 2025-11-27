class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0;
        vector<long long> kSum = vector<long long>(k, LLONG_MAX);
        long long answer = LLONG_MIN;
        kSum[k-1] = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            if (kSum[i%k] != LLONG_MAX) {
                answer = max(answer, prefixSum - kSum[i%k]);
            }
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return answer;
    }
};