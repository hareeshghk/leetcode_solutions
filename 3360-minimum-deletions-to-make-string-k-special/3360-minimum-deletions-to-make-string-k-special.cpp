#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int minimumDeletions(string word, int k) {
        vector<int> count = vector<int>(26, 0);

        for (auto ch : word) {
            count[ch-'a']++;
        }

        sort(count.begin(), count.end(), [](int a, int b) {
            return a>b;
        });

        int last = 25;
        while (count[last] == 0) last--;
        dp = vector<vector<int>>(last+1, vector<int>(last+1, -1));
        return getMin(count, 0, last, k);
    }
private:
    int getMin(vector<int> &c, int s, int l, int k) {
        if (s==l) return 0;

        if (c[s] - c[l] <= k) {
            return getMin(c, s+1, l, k);
        }

        if (dp[s][l] != -1) return dp[s][l];

        return dp[s][l] = min(c[s]-(c[l] + k) + getMin(c, s+1, l, k), c[l] + getMin(c, s, l-1, k));
    }
};
