class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> result1(n);
        for (int i = 0; i < n; ++i) {
            if (grid[m-1][i] == 1) {
                if (i == n-1 || grid[m-1][i+1] == -1) {
                    result1[i] = -1;
                } else {
                    result1[i] = i+1;
                }
            } else {
                if (i == 0 || grid[m-1][i-1] == 1) {
                    result1[i] =-1;
                } else {
                    result1[i] = i-1;
                }
            }
        }
        
        vector<int> result2(n);
        for (int i = m-2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (j == n-1 || grid[i][j+1] == -1) {
                        result2[j] = -1;
                    } else {
                        result2[j] = result1[j+1];
                    }
                } else {
                    if (j == 0 || grid[i][j-1] == 1) {
                        result2[j] =-1;
                    } else {
                        result2[j] = result1[j-1];
                    }
                }
            }
            result1 = result2;
        }
        return result1;
    }
};