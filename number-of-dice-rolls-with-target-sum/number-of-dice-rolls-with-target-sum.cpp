#include <vector>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int>(target+1, -1));
        return numrolls(n,k,target);
    }
    vector<vector<int>> dp;
    int numrolls(int remaining, int k, int target) {
        if (remaining == 0) return (target==0)?1:0;
        if (target<=0) return 0;
        if (dp[remaining][target] != -1) return dp[remaining][target];
        int count = 0;
        for (int i = 1; i <=k; ++i) {
            count = (count+numrolls(remaining-1, k, target-i))%1000000007;
        }
        dp[remaining][target] = count;
        return count;
    }
};
