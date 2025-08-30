#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // taking first i elements in s1 and first j elemnets in s2.
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        dp[0][0] = 0;
        
        // first row filling;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i-1]+ (int)s2[i-1];
        }
        
        // first column filling;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0]+ (int)s1[i-1];
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i-1][j]+ (int)s1[i-1], dp[i][j-1]+(int)s2[j-1]);
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
