#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        
        vector<int> dp1(n+1, 10001), dp2(n+1);
        // dp1[0] = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i*i <= j)
                    dp2[j] = min(dp1[j], 1+dp2[j-i*i]);
                else
                    dp2[j] = dp1[j];
            }
            dp1 = dp2;
        }
        return dp1[n];
    }
};
