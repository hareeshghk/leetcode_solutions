class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long minTime = Integer.MAX_VALUE;
        
        int n = time.length;
        
        for (int i = 0; i < n; ++i) {
            minTime = Math.min(minTime, time[i]);
        }
        
        long left = 1;
        long right = minTime * totalTrips;
        
        while (left < right) {
            long mid = left + (right-left)/2;
            
            if (eligible(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
    boolean eligible(int[] time, long k, int totalTrips) {
        long s = 0;
        
        for (int i = 0; i < time.length; ++i) {
            s += k/time[i];
        }
        return s >= totalTrips;
    }
}