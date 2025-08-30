#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int maxlength = 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1+((i-1>=0 && j-1>=0)?dp[i-1][j-1]:0);
                    maxlength = max(maxlength, dp[i][j]);
                }
            }
        }
        return maxlength;
    }
};
