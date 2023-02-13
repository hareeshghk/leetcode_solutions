class Solution {
    public int countOdds(int low, int high) {
        int numCount = high-low+1;
        
        if (numCount%2 == 0) {
            return numCount/2;
        } else {
            if (low%2==0) {
                return numCount/2;
            } else {
                return (numCount/2)+1;
            }
        }
    }
}