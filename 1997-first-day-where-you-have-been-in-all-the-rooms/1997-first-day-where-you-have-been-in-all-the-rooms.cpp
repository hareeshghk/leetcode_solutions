#include <vector>

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        
        vector<int> dp(n, 0);
        
        dp[0] = 0;
        int mod = 1000000007;
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i-1] + 2 + (dp[i-1] - dp[nextVisit[i-1]]))%mod;
            if (dp[i] < 0) dp[i] +=mod;
        }
        return dp[n-1]%mod;
    }
};
