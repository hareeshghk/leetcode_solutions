#include <algorithm>
#include <vector>

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefixsums(n,0);
        prefixsums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsums[i] = prefixsums[i-1]+nums[i];
        }
        vector<vector<int>> dp(m+1, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            dp[1][i] = prefixsums[n-1]-((i-1>=0)?prefixsums[i-1]:0);
        }
        
        for (int k =2;k<=m;k++) {
            for (int i =0; i <=n-k;++i) {
                int minval = INT_MAX;
                for (int j = i; j <=n-k; ++j) {
                    int cursum = prefixsums[j]-((i-1>=0)?prefixsums[i-1]:0);
                    int nextminmaxsum = dp[k-1][j+1];
                    minval = min(minval, max(cursum, nextminmaxsum));
                    if (cursum > minval) break;
                }
                dp[k][i] = minval;
            }
        }
        return dp[m][0];
    }
};
