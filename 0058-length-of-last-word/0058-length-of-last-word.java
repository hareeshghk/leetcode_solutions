class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        int n = s.length();
        for (int i = n-1; i >= 0;) {
            if (s.charAt(i) != ' ') {
                count = 0;
                while (i >= 0 && s.charAt(i) != ' ') {
                    count++;
                    --i;
                }
                break;
            } else {
                --i;
            }
        }
        return count;
    }
}