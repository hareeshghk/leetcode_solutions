class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // we can do binary search for answer
        // M*N logN

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] += (i!=0?mat[i-1][j]:0);
                mat[i][j] += (j!=0?mat[i][j-1]:0);
                mat[i][j] -= ((i!=0 && j!=0)?mat[i-1][j-1]:0);
            }
        }

        int left = 1, right = min(m,n);
        int answer = 0;
        while(left <= right) {
            int mid = left + ((right-left)/2);

            if (isPossible(mat, threshold, mid)) {
                left = mid+1;
                answer = mid;
            } else {
                right = mid-1;
            }
        }
        return answer;
    }
private:
    bool isPossible(vector<vector<int>>& mat, int t, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = k-1; i < m; ++i) {
            for (int j = k-1; j < n; ++j) {
                int currentSum = mat[i][j];
                currentSum -= ((j-k)>=0?mat[i][j-k]:0);
                currentSum -= ((i-k)>=0?mat[i-k][j]:0);
                currentSum += (((i-k)>=0 && (j-k)>=0)?mat[i-k][j-k]:0);

                if (currentSum <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};