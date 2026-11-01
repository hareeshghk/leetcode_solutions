class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // identify bad oranges
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> badOranges = queue<tuple<int, int, int>>();
        int goodOranges = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    badOranges.push({i, j, 0});
                } else if (grid[i][j] == 1) {
                    goodOranges++;
                }
            }
        }

        auto dirs = vector<vector<int>>{{0,-1},{-1, 0},{0, 1},{1, 0}};
        int answer = 0;
        // spreadout for bad oranges throug bfs way.
        while (!badOranges.empty()) {
            auto badOrange = badOranges.front();
            badOranges.pop();

            auto [x, y, d] = badOrange;

            for (auto dir : dirs) {
                int nx = x+dir[0];
                int ny = y+dir[1];
                int nd;

                if (nx >= 0 && nx < m && ny>=0 && ny < n && grid[nx][ny] == 1) {
                    nd = d + 1;
                    grid[nx][ny] = 2;
                    goodOranges--;
                    badOranges.push({nx, ny, nd});
                    answer = max(answer, nd);
                }
            }
        }

        if (goodOranges != 0) return -1;

        // return maximum of minium distance from bad orange to good one.
        return answer;
    }
};