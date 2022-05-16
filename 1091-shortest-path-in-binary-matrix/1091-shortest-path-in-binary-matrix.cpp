class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // auto minvector = [](vector<int> &a, vector<int> &b) {
        //     return a[0]>b[0];
        // };
        // priority_queue<vector<int>, vector<vector<int>>, decltype(minvector)> pq(minvector);
        
        queue<vector<int>> q;
        
        int n = grid.size();
        
        if (grid[0][0] == 1) return -1;
        
        function<bool(int, int)> valid = [n](int a, int b) {
          return (a>=0 && a<n) &(b>=0 && b<n);  
        };
        
        vector<vector<int>> dirs = {{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        q.push({1, 0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur[1]==n-1 && cur[2]==n-1) return cur[0];
            
            int nextx, nexty;
            for (auto dir : dirs) {
                nextx = cur[1]+dir[0];
                nexty = cur[2]+dir[1];
                if (valid(nextx, nexty) && grid[nextx][nexty] == 0) {
                    q.push({cur[0]+1, nextx, nexty});
                    grid[nextx][nexty] = 1;
                }
            }
        }
        return -1;
    }
};