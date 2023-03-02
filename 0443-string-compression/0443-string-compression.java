class Solution {
    public int compress(char[] chars) {
        int ans_idx = 0;
        
        for (int i = 0; i < chars.length;) {
            int j = i+1;
            while (j < chars.length && chars[j]==chars[i]) {
                j++;
            }
            
            chars[ans_idx++] = chars[i];
            
            // j-i is the number of repeating chars[i]
            if (j-i > 1) {
                for (char c : Integer.toString(j-i).toCharArray()) {
                    chars[ans_idx++] = c;
                }
            }
            i = j;
        }
        return ans_idx;
    }
    
    private StringBuilder GetConvertedCount(int n) {
        if (n==1) {
            return null;
        }
        
        StringBuilder s = new StringBuilder();
        
        while (n!=0) {
            s.append(n%10);
            n/=10;
        }
        
        s.reverse();
        
        return s;
    }
}