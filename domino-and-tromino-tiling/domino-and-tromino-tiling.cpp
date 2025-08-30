#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1000000007;
    enum state {
      FC, PU, PL
    };
    int numTilings(int n) {
        dp.resize(n+1, vector<int>(3, -1));
        return numtilings(n, FC);
    }
    vector<vector<int>> dp;
    int numtilings(int remaining, state s) {
        if (remaining == 1) {
            return 1;
        }
        if (remaining == 0) {
            if (s==FC) return 1;
            else return 0;
        }
        if (dp[remaining][s] != -1) return dp[remaining][s];
        int count = 0;
        if (s==FC) {
            count = (count + numtilings(remaining-1,FC))%mod;
            count = (count + numtilings(remaining-2,FC))%mod;
            count = (count + numtilings(remaining-2,PU))%mod;
            count = (count + numtilings(remaining-2,PL))%mod;
        } else if (s==PU) {
            count = (count + numtilings(remaining-1,PL))%mod;
            count = (count + numtilings(remaining-1,FC))%mod;
        } else {
            count = (count + numtilings(remaining-1,PU))%mod;
            count = (count + numtilings(remaining-1,FC))%mod;
        }
        dp[remaining][s] = count;
        return count;
    }
};
