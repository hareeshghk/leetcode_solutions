#include <vector>
using namespace std;

class Solution {
public:
    long long int mod = 1000000007;
    int countOrders(int n) {
        dp.resize(n+1, vector<long long int>(n+1,-1));
        long long int f = 1;
        
        // 0 pickups and 0 drops one way only.
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            f = (f*i)%mod;
            dp[0][i] = f;
        }
        
        return (int)solve(n, 0);
    }
    
    vector<vector<long long int>> dp;
    
    long long int solve(int pickups, int drops) {
        if (pickups == 0) return dp[0][drops];
        
        if (dp[pickups][drops] != -1) return dp[pickups][drops];
        
        if (drops == 0) return (pickups * (solve(pickups-1, drops+1))%mod)%mod;
        
        int result = ((pickups * (solve(pickups-1, drops+1))%mod)%mod + (drops * (solve(pickups, drops-1))%mod)%mod)%mod;
        return dp[pickups][drops] = result;
    }
};
