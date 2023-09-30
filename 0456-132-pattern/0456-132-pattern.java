class Solution {
    public boolean find132pattern(int[] nums) {
        int s3Candidate = Integer.MIN_VALUE;
        
        Stack<Integer> candidates = new Stack<>();
        
        for (int i = nums.length-1; i >= 0; --i) {
            if (nums[i] < s3Candidate) return true;
            
            while (!candidates.isEmpty() && candidates.peek() < nums[i]) {
                s3Candidate = Math.max(s3Candidate, candidates.pop());
            }
            candidates.add(nums[i]);
        }
        
        return false;
    }
}