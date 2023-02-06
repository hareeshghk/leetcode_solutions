class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int numelems = nums.length;

        int[] maxRightSums = new int[numelems];


        maxRightSums[numelems-1] = nums[numelems-1];
        int suffixSum = maxRightSums[numelems-1];
        for (int i = numelems-2; i >= 0; i--) {
            suffixSum += nums[i];
            maxRightSums[i] = Math.max(maxRightSums[i+1], suffixSum);
        }

        int answer = nums[0];
        int cursum = nums[0];
        int prefixSum = nums[0];

        if (numelems > 1) answer = Math.max(answer, cursum + maxRightSums[1]);
        for (int i = 1; i < numelems; ++i) {
            cursum = Math.max(nums[i], cursum + nums[i]);
            answer = Math.max(answer, cursum);
            prefixSum += nums[i];

            if (i+1 < numelems) answer = Math.max(answer, prefixSum + maxRightSums[i+1]);
        }


        return answer;
    }
}