class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat2.size();
        int n = mat2[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        set<pair<int,int>> mat1_vals, mat2_vals;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (mat1[i][j] != 0) {
                    mat1_vals.insert(pair<int,int>(i, j));
                }
            }
        }
        
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat2[i][j] != 0) {
                    mat2_vals.insert(pair<int,int>(i, j));
                }
            }
        }
        
        
        for (auto v : mat1_vals) {
            for (int i = 0; i < n; ++i) {
                if (mat2_vals.count(pair<int,int>(v.second, i)) != 0) {
                    result[v.first][i] += mat1[v.first][v.second] * mat2[v.second][i];
                }
            }
        }
        
        return result;
    }
};