#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        typedef pair<int,int> cell;
        priority_queue<cell, vector<cell>, greater<cell>> pq;
        
        vector<bool> vis(n*n, false);
        
        pq.push(cell(grid[0][0], 0));
        
        int r,c;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (vis[cur.second]) continue;
            vis[cur.second] = true;
            r = cur.second/n;
            c = cur.second%n;
            if (r == n-1 && c== n-1) return cur.first;
            // 4 conditions.
            if (c+1 < n && !vis[r*n+c+1]) pq.push(cell(max(cur.first, grid[r][c+1]), r*n+c+1));
            if (r+1 < n && !vis[(r+1)*n+c]) pq.push(cell(max(cur.first, grid[r+1][c]), (r+1)*n+c));
            if (r-1 >=0 && !vis[(r-1)*n+c]) pq.push(cell(max(cur.first, grid[r-1][c]), (r-1)*n+c));
            if (c-1 >=0 && !vis[r*n+c-1]) pq.push(cell(max(cur.first, grid[r][c-1]), r*n+c-1));
        }
        return -1;
    }
};
