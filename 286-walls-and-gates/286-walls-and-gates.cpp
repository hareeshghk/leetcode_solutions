#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        
        // bfs to find distances
        queue<int> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.push(i*n+j);
                }
            }
        }
        
        int level = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                auto cur = q.front();
                q.pop();
                
                int x,y;
                x = cur/n;
                y = cur%n;
                
                // left
                if (y-1 >= 0 && rooms[x][y-1] > level) {
                    rooms[x][y-1] = level;
                    q.push(x*n+(y-1));
                }
                // right
                if (y+1 < n && rooms[x][y+1] > level) {
                    rooms[x][y+1] = level;
                    q.push(x*n+(y+1));
                }
                // up
                if (x-1 >=0 && rooms[x-1][y] > level) {
                    rooms[x-1][y] = level;
                    q.push((x-1)*n+y);
                }
                // down
                if (x+1 < m && rooms[x+1][y] > level) {
                    rooms[x+1][y] = level;
                    q.push((x+1)*n+y);
                }
            }
            ++level;
        }
    }
};
