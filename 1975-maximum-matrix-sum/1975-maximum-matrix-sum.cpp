class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // if even number of negatives then make all positive
        // if odd number of negatives then make all positive except one, so choose largest negative value.

        int numNegatives = 0;
        long long overallSum = 0;
        int largestNegative = INT_MIN;
        int smallestPositive = INT_MAX;
        bool zeroExists = false;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] > 0) {
                    overallSum += matrix[i][j];
                    smallestPositive = min(smallestPositive, matrix[i][j]);
                } else if (matrix[i][j] < 0) {
                    overallSum -= matrix[i][j];
                    largestNegative = max(largestNegative, matrix[i][j]);
                    numNegatives++;
                } else {
                    zeroExists = true;
                }
            }
        }

        if (zeroExists) return overallSum;

        if (numNegatives % 2 == 0) return overallSum;

        if (smallestPositive == INT_MAX) {
            return overallSum+(2*largestNegative);
        }

        if (largestNegative*-1 >= smallestPositive) {
            return overallSum-(2*smallestPositive);
        } else {
            return overallSum+(2*largestNegative);
        }
    }
};