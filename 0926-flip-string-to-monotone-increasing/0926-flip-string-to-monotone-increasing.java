class Solution {
    public int minFlipsMonoIncr(String s) {
        int numChars = s.length();

        int numZeroes = 0;

        for (int i = 0; i < numChars; ++i) {
            if (s.charAt(i) == '0') {
               ++numZeroes; 
            }
        }

        int minFlips = numZeroes;

        for (int i = 0; i < numChars; ++i) {
            if (s.charAt(i) == '0') {
               minFlips = Math.min(minFlips, --numZeroes);
            } else {
                ++numZeroes;
            }
        }

        return minFlips;
    }
}