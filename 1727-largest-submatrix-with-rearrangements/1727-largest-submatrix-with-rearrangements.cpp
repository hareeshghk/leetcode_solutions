#include <algorithm>
#include <vector>

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // change matrix with prefix sum style
        int m = matrix.size();
        int n = matrix[0].size();
        
        // O(M*N) time, O(1) space
        for(int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        int answer = 0;
        // O(M*(N*logN + N)) time, O(1) space
        // at every row sort the numbers and find the soultion for max sub matrix.
        for (int i = 0; i < m; ++i) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < n; ++j) {
                answer = max(answer, matrix[i][j]*(j+1));
            }
        }
        
        return answer;
    }
};
