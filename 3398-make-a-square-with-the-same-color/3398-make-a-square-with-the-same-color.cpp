#include <vector>

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        vector<vector<int>> dirs {{0,0}, {0,1}, {1,0}, {1,1}}; 
        for (auto pos : dirs) {
            int numWhites = 0;
            for (auto dir : dirs) {
                if (grid[pos[0]+dir[0]][pos[1]+dir[1]] == 'W') {
                    numWhites++;
                }
            }

            if (numWhites != 2) {
                return true;
            }
        }
        return false;
    }
};
