class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& gr) {
        // lets assume n is smaller so max square can be n
        // fix the size the go into loop. O(M * N^3)
        int m = gr.size();
        int n = gr[0].size();

        vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = gr[i][j] + ((j!=0?grid[i][j-1]:0) + (i!=0?grid[i-1][j]:0)) - ((i!=0 && j !=0)?grid[i-1][j-1]:0);
            }
        }

        int currentSize = min(m, n);
        bool isPossible = false;
        while (currentSize > 1 && !isPossible) {
            for (int i = currentSize-1; i < m; ++i) {
                for (int j = currentSize-1; j < n; ++j) {
                    int row = i;
                    int column = j;
                    int sumItShouldbe = grid[row][column] - (row!=0?grid[row-1][column]:0);
                    if (column-currentSize >= 0) {
                        sumItShouldbe -= grid[row][column-currentSize];
                        sumItShouldbe += (row!=0?grid[row-1][column-currentSize]:0);
                    }

                    bool notPossible = false;

                    for (int currentRow = row-1; currentRow >= max(row+1-currentSize, 0); currentRow--) {
                        int currentSum = grid[currentRow][column] - (currentRow!=0?grid[currentRow-1][column]:0);
                        if (column-currentSize >= 0) {
                            currentSum -= grid[currentRow][column-currentSize];
                            currentSum += (currentRow!=0?grid[currentRow-1][column-currentSize]:0);
                        }

                        if (currentSum != sumItShouldbe) {
                            notPossible = true;
                            break;
                        }
                    }

                    if (notPossible) continue;

                    for (int currentColumn = column; currentColumn >= max(column+1-currentSize, 0); currentColumn--) {
                        int currentSum = grid[row][currentColumn] - (currentColumn!=0?grid[row][currentColumn-1]:0);
                        if (row-currentSize >= 0) {
                            currentSum -= grid[row-currentSize][currentColumn];
                            currentSum += (currentColumn!=0?grid[row-currentSize][currentColumn-1]:0);
                        }

                        if (currentSum != sumItShouldbe) {
                            notPossible = true;
                            break;
                        }
                    }

                    if (notPossible) continue;

                    // right diagonal sum
                    int rightDiagonalSum = 0;
                    for (int k = 0; k < currentSize; ++k) {
                        rightDiagonalSum += gr[row-k][column-k];
                    }
                    if (rightDiagonalSum != sumItShouldbe) continue;

                    // left diagonal sum
                    int leftDiagonalSum = 0;
                    for (int k = 0; k < currentSize; ++k) {
                        leftDiagonalSum += gr[(row+1-currentSize) + k][column-k];
                    }
                    if (leftDiagonalSum != sumItShouldbe) continue;

                    isPossible = true;
                    break;
                }
                if (isPossible) break;
            }
            if (isPossible) break;
            currentSize--;
        }
        return currentSize;
    }
};