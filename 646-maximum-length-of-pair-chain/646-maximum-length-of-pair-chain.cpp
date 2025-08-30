#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto maxpair = [](pair<int,int> &a, pair<int,int> &b) {return a.first > b.first;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(maxpair)> minheap(maxpair);
        
        sort(pairs.begin(),pairs.end(), [](vector<int> &a, vector<int> &b){return a[0]<b[0];});
        int n = pairs.size();
        
        vector<int> dp(n, -1);
        int maxval=0;
        int result = 1;
        for (int i = 0; i < n; ++i) {
            while (!minheap.empty() && minheap.top().first < pairs[i][0]) {
                maxval = max(maxval, dp[minheap.top().second]);
                minheap.pop();
            }
            
            dp[i] = maxval+1;
            // cout << dp[i] << endl;
            result = max(result, maxval+1);
            minheap.push(pair<int,int>(pairs[i][1], i));
        }
        return result;
    }
};
