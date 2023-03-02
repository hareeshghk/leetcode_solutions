class Solution {
    public int compress(char[] chars) {
        int ans_idx = 0;
        
        for (int i = 0; i < chars.length;) {
            int j = i+1;
            while (j < chars.length && chars[j]==chars[i]) {
                j++;
            }
            
            chars[ans_idx++] = chars[i];
            StringBuilder convertedCount = GetConvertedCount(j-i); 
            for (int k = 0; convertedCount != null && k < convertedCount.length(); ++k) {
                chars[ans_idx++] = convertedCount.charAt(k);
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