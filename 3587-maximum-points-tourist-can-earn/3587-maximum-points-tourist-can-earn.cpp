#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        auto dp = vector<int>(n, 0);

        for (int m = 1; m <= k; ++m) {
            auto dp2 = vector<int>(n, 0);
            for (int i = 0; i < n; ++i) {
                int currentMax = 0;
                for (int j = 0; j < n; ++j) {
                    if (j!= i) {
                        currentMax = max(currentMax, dp[j]+travelScore[j][i]);
                    } else {
                        currentMax = max(currentMax, dp[j]+stayScore[m-1][i]);
                    }
                }
                dp2[i] = currentMax;
            }
            dp = dp2;
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};
