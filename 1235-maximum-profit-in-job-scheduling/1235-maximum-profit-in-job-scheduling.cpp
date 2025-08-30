#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> tasks;
        
        int n = startTime.size();
        
        for (int i = 0; i < n; ++i) {
            tasks.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){return a[0]< b[0];});
        
        vector<int> dp(n, -1);
        auto minpair = [](pair<int,int> &a, pair<int,int> &b) {return a.first > b.first;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(minpair)> minheap(minpair);
        
        int result = 0;
        int maxprofit = 0;
        for (int i = 0; i < n; ++i) {
            while (!minheap.empty() && minheap.top().first <= tasks[i][0]) {
                maxprofit = max(maxprofit, dp[minheap.top().second]);
                minheap.pop();
            }
            
            dp[i] = maxprofit+tasks[i][2];
            result = max(result, dp[i]);
            minheap.push(pair<int,int>(tasks[i][1], i));
        }
        return result;
    }
};
