class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(amount+1, vector<int>(n+1, -1));
        return numways(coins, amount, n-1);
    }
    vector<vector<int>> dp;
    int numways(vector<int> &coins, int amount, int idx) {
        if (amount == 0) return 1;
        if (amount<0) return 0;
        if (idx < 0) {
            if (amount == 0) return 1;
            else return 0;
        }
        if (dp[amount][idx] != -1) return dp[amount][idx];
        int a = numways(coins, amount-coins[idx], idx);
        int b = numways(coins, amount, idx-1);
        dp[amount][idx] = a+b;
        return a+b;
    }
};