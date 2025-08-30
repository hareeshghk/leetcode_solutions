#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.resize(n+1, -1);
        return numTree(n);
    }
    int numTree(int n) {
        if (n<=1) return 1;
        if (dp[n] != -1) return dp[n];
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += numTree(i-1)*numTree(n-i);
        }
        dp[n] =result;
        return result;
    }
};
