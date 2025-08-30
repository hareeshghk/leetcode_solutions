#include <vector>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // using firstof row and forst as column as indicator to fill zeroes.
        bool isforstcolzero = false;
        
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) isforstcolzero = true;
            for (int j =1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i =1; i < m; ++i) {
            for (int j =1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j]==0) matrix[i][j] =0;
            }
        }
        
        // first row.
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // first column
        if (isforstcolzero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    
};
