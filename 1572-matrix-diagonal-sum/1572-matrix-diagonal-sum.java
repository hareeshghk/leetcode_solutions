class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        
        int answer = 0;
        
        for (int i = 0; i < n; ++i) {
            answer += mat[i][i];
            answer += mat[n-1-i][i];
        }
        
        if (n%2 == 1) {
            answer -= mat[n/2][n/2];
        }
        
        return answer;
    }
}