class Solution {
    int[] orderValues;
    public boolean isAlienSorted(String[] words, String order) {
        orderValues = new int[26];

        for (int i = 0; i < order.length(); ++i) {
            orderValues[order.charAt(i)-'a'] = i;
        }

        for (int i = 0; i < words.length-1; ++i) {
            if (!validOrder(words[i], words[i+1])) return false;
        }
        return true;
    }

    private boolean validOrder(String s1, String s2) {
        int n1, n2;
        n1 = s1.length();
        n2 = s2.length();

        for (int i = 0; i < Math.min(n1, n2); ++i) {
            if (orderValues[s1.charAt(i)-'a'] == orderValues[s2.charAt(i)-'a']) {
                continue;
            } else if (orderValues[s1.charAt(i)-'a'] < orderValues[s2.charAt(i)-'a']) {
                return true;
            } else {
                return false;
            }
        }

        return n1<=n2;
    }
}