class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return mincost(days, costs, 0);
    }
    vector<int> dp;
    int mincost(vector<int> &days, vector<int> &costs, int idx) {
        if (idx == days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int minval = INT_MAX;
        
        minval = min(minval, mincost(days, costs, idx+1)+costs[0]);
        minval = min(minval, mincost(days, costs, findidx(days, idx, days[idx]+6))+costs[1]);
        minval = min(minval, mincost(days, costs, findidx(days, idx, days[idx]+29))+costs[2]);
        dp[idx] = minval;
        return minval;
    }
    int findidx(vector<int> &days, int start, int target) {
        return upper_bound(days.begin()+start, days.end(), target)-days.begin();
    }
};