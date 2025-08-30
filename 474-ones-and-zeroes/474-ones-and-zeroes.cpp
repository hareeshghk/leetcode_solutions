#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> counter(strs.size());
        
        for (int i = 0; i < strs.size(); ++i) {
            int zcount=0, ocount=0;
            
            for (int j = 0; j < strs[i].length(); ++j) {
                if (strs[i][j] =='0') zcount++;
                else if (strs[i][j] =='1') ocount++;
            }
            counter[i] = pair<int,int>(zcount, ocount);
        }
        
        dp.resize(counter.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        return maxsubset(counter, 0, m, n);
    }
    
    vector<vector<vector<int>>> dp;
    int maxsubset(vector<pair<int,int>> &counter, int idx, int m, int n) {
        if (idx == counter.size()) return 0;
        
        if (dp[idx][m][n] != -1) return dp[idx][m][n];
        
        int result = maxsubset(counter, idx+1, m, n);
        
        if (m-counter[idx].first >=0 && n-counter[idx].second >=0)
            result = max(result, 1 + maxsubset(counter, idx+1, m-counter[idx].first, n-counter[idx].second));
        
        dp[idx][m][n] = result;
        return result;
    }
};
