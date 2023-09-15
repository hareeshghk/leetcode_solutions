class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        for (int i = 0; i < s.length();) {
            if (s.charAt(i) != ' ') {
                int tempCount = 0;
                while (i < s.length() && s.charAt(i) != ' ') {
                    tempCount++;
                    ++i;
                }
                count = tempCount;
            } else {
                ++i;
            }
        }
        return count;
    }
}