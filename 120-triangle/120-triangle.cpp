#include <algorithm>
#include <vector>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp1(n+1, 0);
        vector<int> dp2(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp2[j] = triangle[i][j] + min(dp1[j], dp1[j+1]);
            }
            dp1 = dp2;
        }
        return dp1[0];
    }
};
