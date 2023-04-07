class Solution {
    int[][] dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    int rows, columns;
    public int numEnclaves(int[][] grid) {
        rows = grid.length;
        columns = grid[0].length;
        
        for (int column = 0; column < columns; ++column) {
            if (grid[0][column] == 1) {
                dfs(grid, 0, column);
            }
            
            if (grid[rows-1][column] == 1) {
                dfs(grid, rows-1, column);
            }
        }
        
        for (int row = 0; row < rows; ++row) {
            if (grid[row][0] == 1) {
                dfs(grid, row, 0);
            }
            
            if (grid[row][columns-1] == 1) {
                dfs(grid, row, columns-1);
            }
        }
        
        int answer = 0;
        for (int row = 1; row < rows-1; ++row) {
            for (int column = 1; column < columns-1; ++column) {
                if (grid[row][column] == 1) {
                    ++answer;
                }
            }
        }
        
        return answer;
    }
    
    private void dfs(int[][] grid, int row, int column) {
        grid[row][column] = -1;
        
        int newRow, newColumn;
        for (int[] dir : dirs) {
            newRow = row+dir[0];
            newColumn = column+dir[1];
            
            if (isValid(newRow, 0, rows-1) && isValid(newColumn, 0, columns-1) && grid[newRow][newColumn] == 1) {
                dfs(grid, newRow, newColumn);
            }
        }
    }
    
    private boolean isValid(int value, int min, int max) {
        return (value>=min && value<=max);
    }
}