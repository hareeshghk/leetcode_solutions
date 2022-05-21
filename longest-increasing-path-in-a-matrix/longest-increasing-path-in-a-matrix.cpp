class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dirs;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        dp.resize(m, vector<int>(n, -1));
        dirs = vector<vector<int>>{{0,-1},{0,1},{1,0},{-1,0}};
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == -1) {
                    result = max(result, dfs(i, j, matrix));
                }
            }
        }
        return result;
    }
    
    int dfs(int i, int j, vector<vector<int>> &matrix) {
        if (dp[i][j] != -1) return dp[i][j];
        int result = 1;
        
        int next_i, next_j;
        for (auto dir : dirs) {
            next_i = i+dir[0];
            next_j = j+dir[1];
            if (next_i >=0 && next_i < matrix.size() && next_j>=0 && next_j < matrix[0].size() && matrix[next_i][next_j] > matrix[i][j])
                result = max(result, 1 + dfs(i+dir[0], j+dir[1], matrix));
        }
        
        dp[i][j] = result;
        return result;
    }
};