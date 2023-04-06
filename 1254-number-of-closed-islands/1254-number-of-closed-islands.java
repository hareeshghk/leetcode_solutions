class Solution {
    int rows, columns;
    int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    public int closedIsland(int[][] grid) {
        rows = grid.length;
        columns = grid[0].length;
        
        if (rows <= 2 || columns <= 2) return 0;
        
        for (int column = 0;column<columns; ++column) {
            if (grid[0][column] == 0) {
                dfs(grid, 0, column);
            }
            if (grid[rows-1][column] == 0) {
                dfs(grid, rows-1, column);
            }
        }
        
        for (int row = 0;row<rows; ++row) {
            if (grid[row][0] == 0) {
                dfs(grid, row, 0);
            }
            if(grid[row][columns-1] == 0) {
                dfs(grid, row, columns-1);
            }
        }
        
        int numClosedIslands = 0;
        for (int row = 1; row < rows-1; ++row) {
            for (int column = 1; column < columns-1; ++column) {
                if (grid[row][column] == 0) {
                    dfs(grid, row, column);
                    ++numClosedIslands;
                }
                
            }
        }
        return numClosedIslands;
    }
    
    private void dfs(int[][] grid, int row, int column) {
        grid[row][column] = -1;
        for (int[] dir : dirs) {
            int newRow = row + dir[0];
            int newColumn = column + dir[1];
            
            if (newRow >=0 && newRow < rows && newColumn >=0 && newColumn < columns) {
                if (grid[newRow][newColumn] == 0) {
                    dfs(grid, newRow, newColumn);
                }
            }
        }
    }
}