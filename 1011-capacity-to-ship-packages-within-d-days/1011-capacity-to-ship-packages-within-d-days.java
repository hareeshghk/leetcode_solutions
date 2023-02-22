class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left=0, right=0;
        
        int n = weights.length;
        
        
        for (int i = 0; i < n; ++i) {
            left = Math.max(left, weights[i]);
            right += weights[i];
        }
        
        
        while (left < right) {
            int mid = left + (right-left)/2;
            
            if (isPossibleToFit(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
    boolean isPossibleToFit(int[] weights, int days, int capacity) {
        int current = 0, daysCount = 1;
        for (int weight : weights) {
            current += weight;
            
            if (current > capacity) {
                current = weight;
                daysCount++;
            }
        }
        
        return daysCount <= days;
    }
}