class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int currentFlowerPosition=-2;
        
        int numNewFlowers = 0;
        
        for (int i = 0; i < flowerbed.length; ++i) {
            
            if (flowerbed[i] == 1) {
                int numEmptyPostions = i-currentFlowerPosition-1;
                
                numNewFlowers += (numEmptyPostions-1)/2;
                currentFlowerPosition = i;
            }
        }
        
        numNewFlowers += (flowerbed.length-currentFlowerPosition-1)/2;
        
        return numNewFlowers>=n;
    }
}