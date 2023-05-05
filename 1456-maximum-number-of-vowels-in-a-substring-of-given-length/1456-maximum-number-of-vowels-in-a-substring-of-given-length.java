class Solution {
    public int maxVowels(String s, int k) {
        int cur = 0;
        int answer = 0;
        
        int n = s.length();
        for (int i = 0; i < k && i < n; ++i) {
            if (isVowel(s.charAt(i))) {
                cur++;
            }
        }
        
        answer = Math.max(answer, cur);
        
        for (int i = k; i < n; ++i) {
            if (isVowel(s.charAt(i))) {
                cur++;
            }
            
            if (isVowel(s.charAt(i-k))) {
                cur--;
            }
            
            answer = Math.max(answer, cur);
        }
        
        return answer;
    }
    
    private boolean isVowel(char ch) {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
}