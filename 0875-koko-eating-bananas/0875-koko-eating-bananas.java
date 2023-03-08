// We have h hours
// we want to complete eating all bananas with k rate.
// [3,6,7,11] and we have a k then time taken is ceil(3/k) + ceil(6/k)+ceil(7/k)+ceil(11/k) <= h
// minimum k which follows above condition. and k can be from 1 to max element in the array.
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxPile = Integer.MIN_VALUE;
        
        for (int pile : piles) {
            maxPile = Math.max(maxPile, pile);
        }
        
        int left = 1, right = maxPile;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            
            if (isPossible(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    
    boolean isPossible(int[] piles, int mid, int h) {
        int s = 0;
        
        for (int pile : piles) {
            s += Math.ceil(pile*(1.0)/mid);
        }
        return s <= h;
    }
}