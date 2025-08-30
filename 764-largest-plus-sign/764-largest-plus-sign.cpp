#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int> (n));
        
        vector<bool> zeroes(n*n, false);
        
        int count;
        int ans = 0;
        
        for (auto mine : mines) {
            zeroes[mine[0]*n+mine[1]] = true;
        }
        
        for (int row = 0; row < n; ++row) {
            count = 0;
            for (int col = 0; col < n; ++col) {
                if (!zeroes[row*n+col]) count++;
                else count = 0;
                dp[row][col] = count;
            }
            
            count = 0;
            for (int col =n-1; col >=0; --col) {
                if (!zeroes[row*n+col]) count++;
                else count = 0;
                dp[row][col] = min(dp[row][col], count);
            }
        }
        
        for (int row = 0; row < n; ++row) {
            count = 0;
            for (int col = 0; col < n; ++col) {
                if (!zeroes[col*n+row]) count++;
                else count = 0;
                dp[col][row] = min(dp[col][row], count);
            }
            
            count = 0;
            for (int col =n-1; col >=0; --col) {
                if (!zeroes[col*n+row]) count++;
                else count = 0;
                dp[col][row] = min(dp[col][row], count);
                ans = max(ans, dp[col][row]);
            }
        }
        return ans;
    }
};
