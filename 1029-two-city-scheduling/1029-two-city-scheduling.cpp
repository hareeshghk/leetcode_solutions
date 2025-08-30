#include <algorithm>
#include <vector>

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        dp.resize(2*n, vector<int>(n+1, -1));
        return findcosts(costs, 0, 0, 0, n);
    }
    vector<vector<int>> dp;
    int findcosts(vector<vector<int>> &costs, int idx, int c1, int c2, int n) {
        if (idx == 2*n) return 0;
        // cout << idx << " " << c1 << endl;
        
        if (dp[idx][c1] != -1) return dp[idx][c1];
        if (c1 == n) {
            int result = 0;
            int j = idx;
            while (idx < 2*n) {
                result += costs[idx][1];
                idx++;
            }
            dp[j][c1] = result;
            return result;
        }
        
        if (c2 == n) {
            int result = 0;
            int j = idx;
            while (idx < 2*n) {
                result += costs[idx][0];
                idx++;
            }
            dp[j][c1] = result;
            return result;
        }
        
        int choosefirst = findcosts(costs, idx+1, c1+1, c2, n)+costs[idx][0];
        int choosesecond = findcosts(costs, idx+1, c1, c2+1, n)+costs[idx][1];
        dp[idx][c1] = min(choosefirst, choosesecond);
        return min(choosefirst, choosesecond);
    }
};
