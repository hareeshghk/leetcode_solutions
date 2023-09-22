class Solution {
    public boolean isSubsequence(String s, String t) {
        int i, j;
        i = s.length()-1;
        j = t.length()-1;
        
        while (j >= 0 && i >= 0) {
            if (s.charAt(i) == t.charAt(j)) {
                i--;
            }
            
            j--;
        }
        
        return i < 0;
    }
}