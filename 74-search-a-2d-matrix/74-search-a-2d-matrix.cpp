#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left =0,right =m*n-1, x,y;
        while (left <= right) {
            int mid = (left+right)/2;
            x = mid/n;
            y = mid%n;
            if (matrix[x][y] == target) return true;
            if (target < matrix[x][y]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return false;
    }
};
