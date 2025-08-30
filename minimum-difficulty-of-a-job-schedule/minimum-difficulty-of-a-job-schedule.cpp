#include <algorithm>
#include <vector>

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n<d) return -1;
        dp.resize(n, vector<int>(d+1, -1));
        return mindiff(jobDifficulty, 0, 1, d);
    }
    vector<vector<int>> dp;
    int mindiff(vector<int> &diff, int idx, int day, int maxdays) {
        if (dp[idx][day] != -1) return dp[idx][day];
        if (day == maxdays) {
            int maxval = diff[idx];
            for (int i = idx; i < diff.size(); i++) {
                maxval = max(maxval, diff[i]);
            }
            dp[idx][day] = maxval;
            return maxval;
        }
        
        int maxval = diff[idx];
        int result = INT_MAX;
        for (int i = idx; i < diff.size() - (maxdays-day); i++) {
            maxval=max(maxval, diff[i]);
            result = min(result, maxval+mindiff(diff,i+1, day+1, maxdays));
        }
        dp[idx][day] = result;
        return result;
    }
};
