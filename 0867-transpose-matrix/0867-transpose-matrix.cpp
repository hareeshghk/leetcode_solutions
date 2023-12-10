class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        vector<vector<int>> answer = vector<vector<int>>(columns, vector<int>(rows));
        
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < columns; ++col) {
                answer[col][row] = matrix[row][col];
            }
        }
        
        return answer;
    }
};