class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        
        int left=0, right=n-1, top=0, bottom=n-1;
        int count = 1;
        while (left <= right && top <= bottom) {
            int i,j,k,l;
            
            i = left;
            while (i <= right) {
                matrix[top][i++] = count++;
            }
            top++;
            
            j = top;
            while(j <=  bottom) {
                matrix[j++][right] = count++;
            }
            right--;
            
            k = right;
            while (bottom >= top && k >= left) {
                matrix[bottom][k--] = count++;
            }
            bottom--;
            
            l = bottom;
            while (l>=top && left <= right) {
                matrix[l--][left] = count++;
            }
            left++;
        }
        return matrix;
    }
}