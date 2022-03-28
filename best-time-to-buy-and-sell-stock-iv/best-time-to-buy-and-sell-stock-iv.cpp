class Solution {
public:
    vector<int> prices;
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        if (prices.size() == 0) return 0;
        return recurse(prices.size()-1, false, k);
    }
    unordered_map<string, int> dp;
    int recurse(int idx, int hold, int numleft) {
        if (numleft == 0) return 0;
        
        if (idx == 0) {
            if (hold) {
                return -prices[0];
            } else {
                return 0;
            }
        }
        string matcher = to_string(idx)+","+to_string(hold)+","+to_string(numleft);
        if (dp.find(matcher) != dp.end()) return dp[matcher];
        
        int result;
        if (!hold) {
            result =  max(recurse(idx-1, !hold, numleft)+prices[idx], recurse(idx-1, hold, numleft));
        } else {
          result = max(recurse(idx-1, !hold, numleft - 1)-prices[idx], recurse(idx-1, hold, numleft));  
        }
        dp[matcher] = result;
        return result;
    }
};