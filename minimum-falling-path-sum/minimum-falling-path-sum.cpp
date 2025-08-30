#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i =1;i<m; i++) {
            for (int j =0;j<n;j++) {
                matrix[i][j] +=min(matrix[i-1][j],min((j+1<n)?matrix[i-1][j+1]:INT_MAX, (j-1>=0)?matrix[i-1][j-1]:INT_MAX));
            }
        }
        
        int minval = matrix[m-1][0];
        for (int i = 0; i <n;i++) {
            minval = min(minval, matrix[m-1][i]);
        }
        return minval;
    }
};
