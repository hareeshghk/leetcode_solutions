class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // prefix sum + binary serach.
        // O(N) for prefix sum, N log N as we need to do binary search at every index.

        int n = nums.size();
        vector<long long> pfSum = vector<long long>(n, 0);
        pfSum[0] = nums[0];
        long long answer = 0;
        if (nums[0] < k) {
            ++answer;
        }
        for (int i = 1; i < n; ++i) {
            pfSum[i] = pfSum[i-1]+nums[i];

            int minIndexSatisfying = bsearch(pfSum, 0, i, k);

            answer += max(0, i-minIndexSatisfying+1);
        }
        return answer;
    }
private:
    int bsearch(vector<long long> &pf, int left, int right, long long k) {
        int c = right;
        int result = right+1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            long long cursum = pf[c]-(mid!=0?pf[mid-1]:0);

            if (cursum * (c-mid+1) < k) {
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return result;
    }
};