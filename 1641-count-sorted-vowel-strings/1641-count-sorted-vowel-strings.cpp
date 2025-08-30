#include <vector>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        dp.resize(n+1, vector<int>(5, -1));
        return count(n, 0);
    }
    vector<vector<int>> dp;
    int count(int n, int idx) {
        if (idx == 5) return 0;
        
        if (idx == 4) return 1;
        
        if (n==1) return 5-idx;
        
        if (dp[n][idx] != -1) return dp[n][idx];
        
        int result = 0;
        for (int i = idx; i < 5; ++i) {
            result += count(n-1, i);
        }
        dp[n][idx] = result;
        return result;
    }
};
