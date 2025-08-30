#include <algorithm>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
    vector<int> count;
    int n;
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 0);
        count.resize(n, 1);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    int counts(int x) {
        return count[find(x)];
    }
    
    // subtracting one because top of shelf is not a brick.
    int top() {
        return counts(n-1) - 1;
    }
    
    void unionfind(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return;
        
        if (rank[px] < rank[py]) {
            int temp = px;
            px = py;
            py = temp;
        }
        
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
        
        count[px] += count[py];
        parent[py] = px;
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> gridcopy;
        int m,n;
        

        gridcopy = grid;
        m = grid.size();
        n = grid[0].size();
        
        for (auto hit : hits) {
            gridcopy[hit[0]][hit[1]] = 0;
        }
        
        auto dsu = DSU(m*n + 1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gridcopy[i][j] == 0) continue;
                if (i==0) {
                    dsu.unionfind(m*n, i*n+j);
                }
                
                if (i-1 >=0 && gridcopy[i-1][j] == 1) {
                    dsu.unionfind(i*n+j, (i-1)*n+j);
                }
                
                if (j-1 >=0 && gridcopy[i][j-1] == 1) {
                    dsu.unionfind(i*n+j, i*n+j-1);
                }
            }
        }
        
        vector<int> result(hits.size(), 0);
        
        for (int k = hits.size()-1; k >=0; k--) {
            auto  h = hits[k];
            
            if (grid[h[0]][h[1]] == 0) continue;
            
            int prehit = dsu.top();
            int i, j;
            if (h[0] == 0) {
                dsu.unionfind(m*n, h[0]*n+h[1]);
            }
            
            i = h[0]-1;
            j = h[1];
            if (i>=0 && gridcopy[i][j] == 1) {
                dsu.unionfind(h[0]*n+h[1], i*n + j);
            }
            i = h[0]+1;
            j = h[1];
            if (i<m && gridcopy[i][j] == 1) {
                dsu.unionfind(h[0]*n+h[1], i*n + j);
            }
            i = h[0];
            j = h[1]-1;
            if (j>=0 && gridcopy[i][j] == 1) {
                dsu.unionfind(h[0]*n+h[1], i*n + j);
            }
            i = h[0];
            j = h[1]+1;
            if (j<n && gridcopy[i][j] == 1) {
                dsu.unionfind(h[0]*n+h[1], i*n + j);
            }
            gridcopy[h[0]][h[1]] = 1;
            result[k] = max(0, dsu.top()-prehit - 1);
        }
        return result;
    }
};
