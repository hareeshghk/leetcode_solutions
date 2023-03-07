class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long minTime = Arrays.stream(time).min().getAsInt();
        
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