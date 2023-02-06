class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int gcd = GCD(str1.length(), str2.length());

        String expectedGCDString = str1.substring(0, gcd);

        if (str1.equals(getCopiedString(expectedGCDString, str1.length()/gcd)) &&
          str2.equals(getCopiedString(expectedGCDString, str2.length()/gcd))) {
              return expectedGCDString;
          }
        return "";
    }

    private String getCopiedString(String a, int n) {
        String answer = "";
        for (int i = 0; i < n; ++i) {
            answer = answer + a;
        }
        return answer;
    }

    private int GCD(int a, int b) {
        if (b == 0) return a;

        return GCD(b, a%b);
    }
}