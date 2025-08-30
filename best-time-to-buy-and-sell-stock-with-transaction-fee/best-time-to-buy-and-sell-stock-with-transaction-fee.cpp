#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return maxprofit(prices, 0, 0, fee);
    }
    vector<vector<int>> dp;
    int maxprofit(vector<int>&prices, int idx, int holding, int fee) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][holding] != -1) return dp[idx][holding];
        int result = INT_MIN;
        result = maxprofit(prices, idx+1, holding, fee);
        if (holding == 0) {
            result = max(result, maxprofit(prices, idx+1, 1, fee)-prices[idx]);
        } else {
            result = max(result,maxprofit(prices, idx+1, 0, fee)+prices[idx]-fee);
        }
        dp[idx][holding] = result;
        return result;
    }
};
