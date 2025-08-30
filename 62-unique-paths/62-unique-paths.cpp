#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp1(n, 1), dp2(n,1);
        
        for (int i = 1; i < m; i++) {
            for (int j =1; j < n; j++) {
                dp2[j] = dp1[j]+dp2[j-1];
            }
            dp1 = dp2;
        }
        
        return dp1[n-1];
        
    }
};
