// One pile in an hour.
// p bananas in a pile. Time taken to eat p bananas is ceil(b/k) where k is the rate.
// step(5.7) = 5, ceil(5.7) = 6
// 10 banans and rate is 3 => 3 + 3 + 3 + 1 => 4 hours
// [3,6,7,11] => 11 is maximum value for k and min value is 1.
// ceil(3/k) + ceil(6/k)+ceil(7/k) + ceil(11/k) <= h
// binary serach.
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxValue = Integer.MIN_VALUE;
        
        for (int pile : piles) {
            maxValue = Math.max(maxValue, pile);
        }
        
        int left = 1, right = maxValue;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            
            if (isPossibleToEat(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
    
    boolean isPossibleToEat(int[] piles, int k, int h) {
        int s = 0;
        
        for (int pile : piles) {
            s += pile/k;
            
            if (pile % k != 0) {
                s++;
            }
        }
        
        return s <= h;
    }
}