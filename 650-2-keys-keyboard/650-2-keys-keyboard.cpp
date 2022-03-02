class Solution {
public:
    int n;
    int minSteps(int n) {
        this->n = n;
        dp.resize(n+1, vector(n+1, -1));
        return minSteps(1, 0);
    }
    
    vector<vector<int>> dp;
    
    int minSteps(int cur, int copy) {
        if (cur == n) return 0;
        
        if (cur > n) return 100000;
        if (dp[cur][copy] != -1) return dp[cur][copy];
        
        
        int result = 100000;
        
        if (copy != cur) {
            result = min(result, 1 + minSteps(cur, cur));
        }
        
        if (copy != 0) {
            result = min(result, 1 + minSteps(cur+copy, copy));
        }
        
        dp[cur][copy] = result;
        return result;
    }
};