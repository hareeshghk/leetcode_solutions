class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // we want to find min boundart for every point.
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        vector<bool> visited(m*n, false);
        
        // filling pq with corners and not adding any value from them as they are corners.
        for (int i = 0; i < m; ++i) {
            visited[i*n+(n-1)] = true;
            visited[i*n] = true;
            pq.push(pair<int,int>(heightMap[i][n-1], i*n+(n-1)));
            pq.push(pair<int,int>(heightMap[i][0], i*n));
        }
        for (int i = 0; i < n; ++i) {
            visited[i] = true;
            visited[(m-1)*n+i] = true;
            pq.push(pair<int,int>(heightMap[m-1][i], (m-1)*n+i));
            pq.push(pair<int,int>(heightMap[0][i], i));
        }
        
        vector<vector<int>> direction {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int i, j;
            i = cur.second/n;
            j = cur.second%n;
            for(int k = 0; k<4;++k) {
                int neighbour_i = i+direction[k][0];
                int neighbour_j = j+direction[k][1];
                if (neighbour_i <0||neighbour_i>=m||neighbour_j<0||neighbour_j>=n||visited[neighbour_i*n+neighbour_j]) {
                    continue;
                }
                ans += max(0, cur.first - heightMap[neighbour_i][neighbour_j]);
                pq.push(pair<int,int>(max(cur.first,heightMap[neighbour_i][neighbour_j]), neighbour_i*n+neighbour_j));
                visited[neighbour_i*n+neighbour_j] = true;
            }
        }
        return ans;
    }
};