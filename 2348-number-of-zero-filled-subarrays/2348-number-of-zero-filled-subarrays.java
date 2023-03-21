class Solution {
    public long zeroFilledSubarray(int[] nums) {
        
        int curNonZero = -1;
        long answer = 0;
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                long contiguous = i-curNonZero-1;
                answer += (contiguous * (contiguous+1))/2;
                curNonZero = i;
            }
        }
        
        long contiguous = nums.length-curNonZero-1;
        answer += (contiguous * (contiguous+1))/2;
        
        return answer;
    }
}