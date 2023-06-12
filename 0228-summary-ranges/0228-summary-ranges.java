class Solution {
    public List<String> summaryRanges(int[] nums) {
        int n = nums.length;
        
        List<String> answer = new ArrayList<>();
        
        if (n == 0) {
            return answer;
        }
        
        int start = nums[0], end = nums[0];
        
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == end + 1) {
                end++;
                continue;
            }
            
            answer.add(getRangeFromStartAndEnd(start, end));
            
            start = nums[i];
            end = start;
        }
        
        // Final one is always not added so adding it here.
        answer.add(getRangeFromStartAndEnd(start, end));
        
        return answer;   
    }
    
    private String getRangeFromStartAndEnd(int start, int end) {
        if (start == end) {
            return String.valueOf(start);
        }
        
        return String.valueOf(start) + "->" + String.valueOf(end);
    }
}