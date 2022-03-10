class Solution {
    vector<int> parents;
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parents.resize(m*n, 0);
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (int i = 0; i <m;i++) {
            for (int j = 0; j < n; j++) {
                parents[i*n+j] = i*n+j;
            }
        }
        
        vector<int> result;
        int count = 0;
        
        vector<vector<int>> dirs {{0,-1},{0,1},{-1,0},{1,0}};
        for (auto pos : positions) {
            int posx = pos[0];
            int posy = pos[1];
            if (grid[posx][posy] == 1) {
                result.push_back(count);
                continue;
            }
            count++;
            for (auto dir : dirs) {
                if (valid(posx+dir[0], posy+dir[1], m, n) && grid[posx+dir[0]][posy+dir[1]] == 1) {
                    if (unionfind(posx*n+posy, (posx+dir[0])*n + posy+dir[1])) {
                        count--;
                    }
                }
            }
            grid[posx][posy] = 1;
            result.push_back(count);
        }
        return result;
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        
        parents[pb] = pa;
        return true;
    }
    
    int find(int a) {
        if (parents[a] != a) {
            parents[a] = find(parents[a]);
        }
        return parents[a];
    }
    
    int valid(int a, int b, int m, int n) {
        return (a>=0 && a < m && b>=0 && b<n);
    }
};