class Solution {
    public char findTheDifference(String s, String t) {
        if (t.length() == 1) {
            return t.charAt(0);
        }
        
        int residue = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            residue ^= ((s.charAt(i)-'a') ^ (t.charAt(i)-'a'));
        }
        
        residue ^= t.charAt(t.length()-1)-'a';
        
        return (char)('a'+residue);
    }
}