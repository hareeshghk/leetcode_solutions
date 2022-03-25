class DSU {
    vector<int> parent;
    vector<int> jusparent;
    int remaining;
public:
    DSU(int n) {
        parent.resize(n+1);
        jusparent.resize(n+1, -1);
        remaining = n;
        for (int i =1; i<=n; i++) {
            parent[i] = i;
        }
        remaining = n;
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionfind(int a, int b) {
        jusparent[b] = a;
        int pa,pb;
        pa = find(a);
        pb = find(b);
        
        if (pa == pb) return false;
        
        parent[pb] = pa;
        --remaining;
        return true;
    }
    
    int getparent(int x) {
        return parent[x];
    }
    
    int getjustparent(int x) {
        return jusparent[x];
    }
    int getremaining() {
        return remaining;
    }
};

class Solution {
public:
    int count;
    vector<int> duplicate;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU d(n);
        
        vector<int> e2,e1, cycleedge;
        for (auto edge : edges) {
            if (d.getjustparent(edge[1]) != -1) {
                e2 = edge;
                e1 = vector<int>{d.getjustparent(edge[1]), edge[1]};
                continue;
            }
            if (!d.unionfind(edge[0], edge[1])) {
                cycleedge = edge;
            }
        }
        
        if (d.getremaining() == 1) {
            if (cycleedge.size() != 0) return cycleedge;
            return e2;
        }
        return e1;
    }
    
    void dfs(int root, vector<vector<int>> &g, vector<bool> &v) {
        count++;
        v[root] = true;
        for (auto nei : g[root]) {
            if (!v[nei]) {
                dfs(nei, g, v);
            } else {
                duplicate.push_back(root);
                duplicate.push_back(nei);
            }
        }
        
    }
};