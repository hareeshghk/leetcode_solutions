class Solution {
    public int findKthPositive(int[] arr, int k) {
        int expected = 1;
        int missed = 0;
        
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] != expected) {
                missed += arr[i]-expected;
            }
            
            if (missed >= k) {
                int prevmissed = missed - (arr[i]-expected);
                int prevValue = (i-1 >= 0)?arr[i-1]:0;
                
                return prevValue + (k-prevmissed);
            }
            
            expected = arr[i] + 1;
            
        }
        return k+arr.length;
    }
}