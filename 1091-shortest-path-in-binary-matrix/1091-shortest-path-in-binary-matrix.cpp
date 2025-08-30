#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1) return -1;
        
        
        vector<vector<int>> dirs = {{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<int> q;
        q.push(0);
        grid[0][0] = 1;
        
        int curx, cury, nextx, nexty;
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            curx = cur/n;
            cury = cur%n;
            
            if (curx==n-1 && cury==n-1) return grid[curx][cury];

            for (const auto& dir : dirs) {
                nextx = curx+dir[0];
                nexty = cury+dir[1];
                if (((nextx>=0 && nextx<n) &(nexty>=0 && nexty<n)) && grid[nextx][nexty] == 0) {
                    q.push((nextx*n)+nexty);
                    grid[nextx][nexty] = grid[curx][cury]+1;
                }
            }
        }
        return -1;
    }
};
