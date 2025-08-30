#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    vector<int> parent;
    int n;
    vector<bool> visited;
    vector<vector<int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
    int largestIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        // initializing unoin find with size of 1.
        parent.resize(n*n, -1);
        visited.resize(n*n, false);
        
        int ans = 1;
        
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (!visited[i*n+j] && grid[i][j] == 1) {
                    visited[i*n+j] = true;
                    dfs(i*n+j, i*n+j);
                    // cout << -parent[i*n+j] << endl;
                    ans = max(ans, -parent[i*n+j]);
                }
            }
        }
        
        
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ans = max(ans, includezero(i,j));
                }
            }
        }
        return ans;
    }
    
    int includezero(int x, int y) {
        unordered_set<int> uniq_parents;
        
        int p, x1,y1;
        for (int i = 0; i < 4; i++) {
            x1 = x+dirs[i][0];
            y1 = y+dirs[i][1];
            if (isvalid(x1,y1) && grid[x1][y1] == 1) {
                p = find(x1*n+y1);
                if (uniq_parents.find(p) == uniq_parents.end()) {
                    uniq_parents.insert(p);
                }
            }
        }
        
        int result = 1;
        for (auto par : uniq_parents) {
            result += parent[par] * -1;
        }
        return result;
    }
    
    void dfs(int pos, int root) {
        int x,y, x1,y1, newpos;
        x = pos/n;
        y = pos%n;
        
        for (auto dir : dirs) {
            x1 = x+dir[0];
            y1 = y+dir[1];
            newpos = x1*n+y1;
            if (isvalid(x1,y1) && grid[x1][y1] == 1 && !visited[newpos]) {
                visited[newpos] = true;
                unionf(root, newpos);
                dfs(newpos, root);
            }
        }
    }
    
    bool isvalid(int a, int b) {
        return (a>=0 && a < n && b>=0 && b<n);
    }
    
    // find in union find op.
    int find(int x) {
        if (parent[x] < 0) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    // union
    bool unionf(int a, int b) {
        int pa, pb;
        pa = find(a);
        pb = find(b);
        
        if (pa == pb) false;
        
        if (parent[pa] <= parent[pb]) {
            parent[pa] += parent[pb];
            parent[pb] = pa;
        } else {
            parent[pb] += parent[pa];
            parent[pa] = pb;
        }
        return true;
    }
};
