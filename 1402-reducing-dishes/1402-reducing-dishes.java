class Solution {
    int[][] dp;
    public int maxSatisfaction(int[] sat) {
        Arrays.sort(sat);
        int n = sat.length;
        
        int answer = 0, runningSum = 0;
        
        for (int i = n-1; i >= 0; --i) {
            runningSum += sat[i];
            
            if (runningSum < 0) break;
            
            answer += runningSum;
        }
        
        return answer;
    }
}