#include <vector>

class Solution {
    int mod = 1000000007;
    vector<vector<int>> dp;
public:
    int numTilings(int n) {
        // lets calculate cvolumn by column
        // when yo are in a column it can be in three ways  maximum.
        // empty, topfilled, bottomfilled.
        // empty mean then we can fill it in 4 ways.
        // top filled means then can be filled in 2 ways.
        // bottom filled means then it can be filled 2 ways.

        dp = vector<vector<int>>(n+1, vector<int>(3, -1));
        // 0 is empty, 1 is top filled, 2 is bottom filled.
        return getNumTilings(n, 0);  
    }
private:
    int getNumTilings(int c, int state) {
        if (c < 0) return 0;

        if (c == 0) {
            if (state == 0) return 1;
            return 0;
        }

        if (dp[c][state] != -1) return dp[c][state];

        int result = 0;

        if (state == 0) {
            result = (result + getNumTilings(c-1, 0))%mod;
            result = (result + getNumTilings(c-1, 1))%mod;
            result = (result + getNumTilings(c-1, 2))%mod;
            result = (result + getNumTilings(c-2, 0))%mod;
        } else if (state == 1) {
            result = (result + getNumTilings(c-2, 0))%mod;
            result = (result + getNumTilings(c-1, 2))%mod;
        } else {
            result = (result + getNumTilings(c-2, 0))%mod;
            result = (result + getNumTilings(c-1, 1))%mod;
        }
        return dp[c][state]=result;
    }
};
