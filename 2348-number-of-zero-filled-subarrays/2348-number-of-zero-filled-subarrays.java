class Solution {
    public long zeroFilledSubarray(int[] nums) {
        
        int curNonZero = -1;
        long answer = 0;
        
        long contiguous;
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                contiguous = i-curNonZero-1;
                answer += (contiguous * (contiguous+1))/2;
                curNonZero = i;
            }
        }
        
        contiguous = nums.length-curNonZero-1;
        answer += (contiguous * (contiguous+1))/2;
        
        return answer;
    }
}