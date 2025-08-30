#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0, counter = 0;
        
        vector<int> dp(n, 0);
        
        for (int i = 1; i < n; ++i) {
            if (s[i]==')') {
                if (s[i-1] =='(') {
                    dp[i] = 2 + ((i-2)>=0?dp[i-2]:0);
                } else {
                    int x = i-dp[i-1]-1;
                    if (x>=0 && s[x] == '(') {
                        dp[i] = dp[i-1] + 2 + (x>=1?dp[x-1]:0);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
