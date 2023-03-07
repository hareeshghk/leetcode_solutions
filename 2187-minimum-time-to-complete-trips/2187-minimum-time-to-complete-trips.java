@FunctionalInterface  
interface Sayable{  
    boolean say(long k);  
}

class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long minTime = Arrays.stream(time).min().getAsInt();
        
        long left = 1;
        long right = minTime * totalTrips;
        
        Sayable eligible = (k) -> {
            long s = 0;
            for (int i = 0; i < time.length; ++i) {
                s += k/time[i];
            }
            return s >= totalTrips;
        };
        
        while (left < right) {
            long mid = left + (right-left)/2;
            
            if (eligible.say(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
}