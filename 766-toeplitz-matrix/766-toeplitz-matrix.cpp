#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int diff;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff = i-j;
                if (diff <=0) {
                    if (matrix[i][j] != matrix[0][-diff]) return false;
                } else {
                    if (matrix[i][j] != matrix[diff][0]) return false;
                }
            }
        }
        return true;
    }
};
