class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        // create dp[i][j] which saus whether string from i to j is polindrome or now
        // dp[i][j] is true if s[i]==s[j] and dp[i+1][j-1] is true

        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));

        // length 1 polindromes.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        int maxlen = 1;

        // length 2 polindromes.
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                maxlen = 2;
            }
        }

        int len = 3;
        for (len = 3; len <= n; ++len) {
            if (len > maxlen + 2) break;
            for (int i = 0; i+len-1 <= n-1; ++i) {
                int j = i+len-1;

                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    maxlen = len;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int j = i+maxlen-1;

            if (dp[i][j]) return s.substr(i, maxlen);
        }

        return "";
    }
};