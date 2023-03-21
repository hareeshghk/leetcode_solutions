class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long answer = 0, numSubArrays = 0;;
        
        for (int num : nums) {
            
            if (num == 0) {
                ++numSubArrays;
            } else {
                numSubArrays = 0;
            }
            answer += numSubArrays;
        }
        
        return answer;
    }
}