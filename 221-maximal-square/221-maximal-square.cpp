#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // i and j represnt max square ending at i-1, j-1 as right bottom corner.
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        int maxsquaresize = 0;
        
        for (int i = 1; i <=m;i++) {
            for (int j =1; j<=n;j++) {
                if (matrix[i-1][j-1] =='0') continue;
                
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                maxsquaresize = max(maxsquaresize, dp[i][j]);
            }
        }
        return maxsquaresize*maxsquaresize;
    }
};
