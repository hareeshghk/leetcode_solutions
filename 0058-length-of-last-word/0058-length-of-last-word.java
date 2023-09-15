class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n;) {
            if (s.charAt(i) != ' ') {
                count = 0;
                while (i < n && s.charAt(i) != ' ') {
                    count++;
                    ++i;
                }
            } else {
                ++i;
            }
        }
        return count;
    }
}