class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Take 0's and do a bfs from them. convert 1's to zeroes and then add them to queue
        // if neighbour is already 0 don't do anything and maintain current distance so next would +1.

        queue<pair<int /*i*/, int /*j*/>> q;

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j=0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        auto dirs = vector<vector<int>>{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >=0 && nx < m && ny>=0 && ny< n) {
                    if (mat[nx][ny] == 1) {
                        mat[nx][ny] = 0;
                        ans[nx][ny] = ans[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};