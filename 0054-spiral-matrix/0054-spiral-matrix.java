class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int left, right, top, bottom;
        
        left = 0;
        right = matrix[0].length-1;
        top = 0;
        bottom = matrix.length-1;
        List<Integer> answer = new ArrayList<>();
        while (left <= right && top <= bottom) {
            int i = left;
            
            while (i <= right) {
                answer.add(matrix[top][i++]);
            }
            top++;
            
            int j = top;
            while (j <= bottom) {
                answer.add(matrix[j++][right]);
            }
            right--;
            
            int k = right;
            while (bottom >= top && k>=left) {
                answer.add(matrix[bottom][k--]);
            }
            bottom--;
            
            int l = bottom;
            
            while(left <= right && l>=top) {
                answer.add(matrix[l--][left]);
            }
            left++;
        }
        return answer;
    }
}