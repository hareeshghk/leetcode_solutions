class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> result(m*n, 0);
        
        int left, right, top, bottom;
        left = 0;right=n-1;top=0;bottom=m-1;
        int idx = 0;
        while (left <= right && top <= bottom) {
            if (left == right) {
                for (int i = top; i <=bottom; i++) {
                    result[idx++] = matrix[i][left];
                }
                break;
            }
            if (top == bottom) {
                for (int i = left; i <= right; i++) {
                    result[idx++] = matrix[top][i];
                }
                break;
            }
            
            // left to right-1
            for (int i =left; i < right; i++) {
                result[idx++] = matrix[top][i];
            }
            // top to bottom-1
            for (int i =top; i < bottom; i++) {
                result[idx++] = matrix[i][right];
            }
            // right to left -1
            for (int i =right; i > left; i--) {
                result[idx++] = matrix[bottom][i];
            }
            // bottom to top-1
            for (int i =bottom; i > top; i--) {
                result[idx++] = matrix[i][left];
            }
            
            left++;right--;
            top++;bottom--;
        }
        return result;
    }
};