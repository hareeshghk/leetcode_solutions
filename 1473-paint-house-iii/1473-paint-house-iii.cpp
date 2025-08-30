#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int result = INT_MAX;
        dp.resize(m, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        for (int i = 1; i <= n; i++) {
            result = min(result, mincosttoapplycolour(houses, cost, 0, i, 1, target));
        }
        return result==INT_MAX?-1:result;
    }
    vector<vector<vector<int>>> dp;
    int mincosttoapplycolour(vector<int> &houses, vector<vector<int>> &costs,int idx, int colour, int nei, int target) {
        if (dp[idx][colour][nei] != -1) return dp[idx][colour][nei];
        if (nei == target) {
            int curcost = 0;
            for (int i = idx; i < houses.size(); ++i) {
                if (houses[i] == 0) {
                    curcost += costs[i][colour-1];
                } else if (houses[i] != colour){
                    dp[idx][colour][nei] = INT_MAX;
                    return INT_MAX;
                }
            }
            dp[idx][colour][nei] = curcost;
            return curcost;
        }
        
        int curcost = 0;
        int mincost = INT_MAX;
        for (int i = idx; i < houses.size()-(target-nei);++i) {
            if (houses[i] == 0) {
                curcost += costs[i][colour-1];
            } else if (houses[i] != colour){
                    break;
            }
            for (int j = 1; j <= costs[0].size(); ++j) {
                if (j==colour) continue;
                int nextcost = mincosttoapplycolour(houses, costs, i+1, j, nei+1, target);
                if (nextcost == INT_MAX) continue;
                mincost = min(mincost, curcost+nextcost);
            }
        }
        dp[idx][colour][nei] = mincost;
        return mincost;
    }
};
