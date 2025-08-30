#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // two ways we can do it
        // dp using previous rows or
        // using combinations logic nc0, nc1, nc2....ncn

        // using dp
        vector<int> dp = vector<int>(rowIndex+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> dp2 = vector<int>(rowIndex+1, 0);
            for (int j = 0; j <= i; ++j) {
                dp2[j] = dp[j] + ((j!=0)?dp[j-1]:0);
            }
            dp = dp2;
        }
        return dp;
    }
};
