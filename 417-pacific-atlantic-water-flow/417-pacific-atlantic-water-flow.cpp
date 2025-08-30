#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> result, dp(m, vector<int>(n, 0));
        
        if (m == 1|| n==1) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result.push_back({i, j});
                }
            }
            return result;
        }
        
        queue<pair<int,int>> iterators;
        
        dp[0][0] = 1;
        dp[0][n-1] = 3;
        dp[m-1][0] = 3;
        dp[m-1][n-1] = 2;
        result.push_back({0, n-1});
        result.push_back({m-1, 0});
        iterators.push(make_pair(0, 0));
        iterators.push(make_pair(0, n-1));
        iterators.push(make_pair(m-1, 0));
        iterators.push(make_pair(m-1, n-1));
        
        // first row fill with 
        for (int i = 1; i < n-1; i++) {
            iterators.push(make_pair(0, i));
            dp[0][i] = 1;
        }
        //first column
        for (int i = 1; i < m-1; i++) {
            iterators.push(make_pair(i, 0));
            dp[i][0] = 1;
        }
        
        // last column
        for (int i = 1; i < m-1; i++) {
            iterators.push(make_pair(i, n-1));
            dp[i][n-1] = 2;
        }
        
        //last row
        for (int i = 1; i < n-1; i++) {
            iterators.push(make_pair(m-1, i));
            dp[m-1][i] = 2;
        }
        
        int x, y;
        vector<vector<int>> dirs{{0,1},{0,-1},{-1,0},{1,0}};
        while (!iterators.empty()) {
            auto cur = iterators.front();
            iterators.pop();
            
            x = cur.first;
            y = cur.second;
            int nextx, nexty;
            for (auto dir : dirs) {
                nextx = x+dir[0];
                nexty = y+dir[1];
                if (nextx < 0||nextx >=m || nexty < 0||nexty >=n || dp[nextx][nexty] == 3) continue;
                if (heights[nextx][nexty] >= heights[x][y] && dp[x][y] != dp[nextx][nexty]) {
                    if (dp[x][y] == 3) {
                        dp[nextx][nexty] = dp[x][y];
                        result.push_back({nextx, nexty});
                    } else if (dp[nextx][nexty] == 0) {
                        dp[nextx][nexty] = dp[x][y];
                    } else {
                        dp[nextx][nexty] = 3;
                        result.push_back({nextx, nexty});
                    }
                    iterators.push(make_pair(nextx, nexty));
                }
            }
        }
        return result;
    }
};
