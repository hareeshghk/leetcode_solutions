class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int maxarea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = ((j==0)?0:dp[i][j-1]) + 1;
                
                    int width = dp[i][j];
                
                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        maxarea = max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
};