class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n, m;
        n = spells.length;
        m = potions.length;
        
        Arrays.sort(potions);
        
        int[] answer = new int[n];
        
        for (int i = 0; i < n; ++i) {
            answer[i] = getValid(spells[i], potions, success);
        }
        
        return answer;
    }
    
    int getValid(int s, int[] p, long success) {
        int low = 0;
        int high = p.length;
        int mid;
        long val;
        while (low < high) {
            mid = low + (high-low)/2;
            val = s;
            val*= p[mid];
            if (val >= success) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        
        return p.length-high;
    }
}