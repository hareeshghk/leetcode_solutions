class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;

        int n = s.length();

        StringBuilder builder = new StringBuilder(n);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j*(numRows-1)-i< n || j*(numRows-1)+i < n; j+=2) {
                if (i == 0 || i == numRows-1) {
                    if (j*(numRows-1)+i < n) builder.append(s.charAt(j*(numRows-1)+i));
                    continue;
                }

                int a, b;

                a = j*(numRows-1)-i;
                b = j*(numRows-1)+i;

                if (a>=0 && a<n) {
                    builder.append(s.charAt(a));
                }

                if (b>=0 && b < n) {
                    builder.append(s.charAt(b));
                }
            }
        }
        return builder.toString();
    }
}