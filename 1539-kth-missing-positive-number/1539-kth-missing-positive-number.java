class Solution {
    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length-1;
        
        int mid;
        
        while (left <= right) {
            mid = left + (right-left)/2;
            
            if (arr[mid]-(mid+1) >= k) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        // This mean missing element is at start only like array started with 5 and we want 4th missing number.
        if (right == -1) {
            return k;
        }
        
        return arr[right]+(k-(arr[right]-(right+1)));
    }
}