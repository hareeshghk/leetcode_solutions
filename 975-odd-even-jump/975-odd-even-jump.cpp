#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        
        dp[n-1][0] = dp[n-1][1] = true;
        
        map<int,int> pos;
        pos[arr[n-1]] = n-1;
        
        int result = 1;
        
        for (int i = n-2; i >=0; --i) {
            if (pos.find(arr[i]) != pos.end()) {
                dp[i][0] = dp[pos[arr[i]]][1];
                dp[i][1] = dp[pos[arr[i]]][0];
            } else {
                auto mingreater = pos.upper_bound(arr[i]);
                auto maxlower = pos.lower_bound(arr[i]);
            
                if (mingreater != pos.end()) {
                    dp[i][0] = dp[mingreater->second][1];
                }
            
                if (maxlower != pos.begin()) {
                    dp[i][1] = dp[(--maxlower)->second][0];
                }
            }
            
            pos[arr[i]] = i;
            
            if (dp[i][0]) ++result;
        }
        return result;
    }
};
