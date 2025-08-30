#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n, {1, -1});
        // if there is an answer subset
        // sorted subset elements will be like k1, k1*k2, k1*k2*k3, k1*k2*k3*k4 .....

        int maxCount = 1, maxCountStartIndex = -1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; j++) {
                if (nums[j]%nums[i] == 0) {
                    if (dp[i].first < dp[j].first +1) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    }
                }
            }
            if (maxCount <= dp[i].first) {
                maxCount = dp[i].first;
                maxCountStartIndex = i;
            }
        }

        vector<int> answer;
        while(maxCountStartIndex != -1) {
            answer.push_back(nums[maxCountStartIndex]);
            maxCountStartIndex = dp[maxCountStartIndex].second;
        }
        return answer;
    }
};
