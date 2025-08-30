#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

    vector<int> minTillNow, maxTillNow(n, 0);

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for (int i = 0; i < n; ++i) {
        minTillNow.push_back(minValue);
        maxTillNow[n-1-i] = maxValue;

        minValue = min(minValue, prices[i]);
        maxValue = max(maxValue, prices[n-1-i]);
    }

    vector<int> dp1(n, 0), dp2(n, 0);

    for (int i = 1; i < n; ++i) {
        dp1[i] = max(dp1[i-1],  (minTillNow[i]==INT_MAX?0:prices[i]-minTillNow[i]));
    }

    for (int i = n-2; i >=0; --i) {
        dp2[i] = max(dp2[i+1], (maxTillNow[i]==INT_MIN?0:maxTillNow[i]-prices[i]));
    }

    int profit = 0;
    for (int i = 0; i < n-1; ++i) {
        profit = max(profit, dp1[i] + dp2[i+1]);
    }
        profit = max(profit, dp2[0]);

    return  profit;
    }
};
