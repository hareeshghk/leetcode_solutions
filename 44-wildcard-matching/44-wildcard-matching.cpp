class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        if (s == p) return true;
        
        if (p == "*") return true;
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        for (int i = 0; i <= m ;i++) {
            dp[i][n] = false;
        }
        dp[m][n] = true;
        
        int k = n-1;
        while (k>=0) {
            if (p[k] == '*') dp[m][k--] = true;
            else break;
        }
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (p[j] == '*') {
                    dp[i][j] = (dp[i][j+1]||dp[i+1][j]);
                }
                else {
                    dp[i][j] = (p[j]=='?' || s[i] == p[j])?dp[i+1][j+1]:false;
                }
            }
        }

        return dp[0][0];
    }
};