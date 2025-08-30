#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n<=2) return n;
        
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){return a[0]<b[0] || (a[0]==b[1] && a[1]<b[1]);});
        
        vector<vector<int>> dp(n, vector<int>(n, 2));
        
        int result = 2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = 2;
                double slope = GetSlope(points[i], points[j]);
                
                for (int k = 0; k < i; ++k) {
                    if (GetSlope(points[k], points[i]) == slope) {
                        dp[i][j] = max(dp[i][j], dp[k][i]+1);
                    }
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
    
    double GetSlope(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return INT_MAX;
        
        double slope = ((b[1]-a[1])*1.0)/(b[0]-a[0]);
        return slope;
    }
};
