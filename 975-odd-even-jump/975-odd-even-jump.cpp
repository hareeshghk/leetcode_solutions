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
                // cout << i << " greater "<< pos[arr[i]] << endl;
                dp[i][1] = dp[pos[arr[i]]][0];
                // cout << i << " lower "<< pos[arr[i]] << endl;
            } else {
                auto mingreater = pos.upper_bound(arr[i]);
                auto maxlower = pos.lower_bound(arr[i]);
            
                if (mingreater != pos.end()) {
                    dp[i][0] = dp[mingreater->second][1];
                    // cout << i << " greater "<< maxlower->second << endl;
                }
            
                if (maxlower != pos.begin()) {
                    dp[i][1] = dp[(--maxlower)->second][0];
                    // cout << i << " lower " << maxlower->second << endl;
                }
            }
            
            pos[arr[i]] = i;
            
            if (dp[i][0]) ++result;
        }
        return result;
    }
};