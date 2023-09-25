class Solution {
    public char findTheDifference(String s, String t) {
        int[] counter = new int[26];
        if (t.length() == 1) {
            return t.charAt(0);
        }
        Arrays.fill(counter, 0);
        
        for (int i = 0; i < s.length(); ++i) {
            counter[s.charAt(i)-'a']++;
            counter[t.charAt(i)-'a']--;
        }
        
        counter[t.charAt(t.length()-1)-'a']--;
        
        for (int i = 0; i < 26; ++i) {
            if (counter[i] == -1) return (char)('a'+i);
        }
        return 'a';
    }
}