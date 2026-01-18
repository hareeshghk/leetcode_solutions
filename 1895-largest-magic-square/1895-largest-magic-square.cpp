class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        // lets assume n is smaller so max square can be n
        // fix the size the go into loop. O(M * N^3)
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefixSum = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i][j] = grid[i][j] + ((j!=0?prefixSum[i][j-1]:0) + (i!=0?prefixSum[i-1][j]:0)) - ((i!=0 && j !=0)?prefixSum[i-1][j-1]:0);
            }
        }

        int currentSize = min(m, n);
        bool isPossible = false;
        while (currentSize > 1 && !isPossible) {
            for (int i = currentSize-1; i < m; ++i) {
                for (int j = currentSize-1; j < n; ++j) {
                    int row = i;
                    int column = j;
                    int sumItShouldbe = getRectangleSum(row, column+1-currentSize, row, column, prefixSum);

                    bool notPossible = false;

                    for (int currentRow = row-1; currentRow >= max(row+1-currentSize, 0); currentRow--) {
                        int currentSum = getRectangleSum(currentRow, column+1-currentSize, currentRow, column, prefixSum);
                        if (currentSum != sumItShouldbe) {
                            notPossible = true;
                            break;
                        }
                    }

                    if (notPossible) continue;

                    for (int currentColumn = column; currentColumn >= max(column+1-currentSize, 0); currentColumn--) {
                        int currentSum = getRectangleSum(row+1-currentSize, currentColumn, row, currentColumn, prefixSum);
                        if (currentSum != sumItShouldbe) {
                            notPossible = true;
                            break;
                        }
                    }

                    if (notPossible) continue;

                    // right diagonal sum
                    int rightDiagonalSum = 0;
                    for (int k = 0; k < currentSize; ++k) {
                        rightDiagonalSum += grid[row-k][column-k];
                    }
                    if (rightDiagonalSum != sumItShouldbe) continue;

                    // left diagonal sum
                    int leftDiagonalSum = 0;
                    for (int k = 0; k < currentSize; ++k) {
                        leftDiagonalSum += grid[(row+1-currentSize) + k][column-k];
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
private:
    inline int getRectangleSum(int startx, int starty, int endx, int endy, vector<vector<int>> &prefixSum) {
        int currentSum = prefixSum[endx][endy];

        if (startx-1 >= 0) {
            currentSum -= prefixSum[startx-1][endy];
        }

        if (starty-1 >= 0) {
            currentSum -= prefixSum[endx][starty-1];
        }
        
        if (starty-1 >= 0 && startx-1 >= 0) {
            currentSum += prefixSum[startx-1][starty-1];
        }

        return currentSum;
    }
};