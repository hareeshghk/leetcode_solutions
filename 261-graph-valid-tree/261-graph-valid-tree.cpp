class DSU {
    vector<int> parents;
public:  
    DSU(int n) {
        parents.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa==pb) return false;
        
        parents[pb] = pa;
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // connected graph and no cycles is called tree.
        // from edges use disjoiny union to find cycle
        // for no cylces we need n-1 edges.
        int e = edges.size();
        
        if (e != n-1) return false;
        
        DSU dsu(n);
        
        for (auto edge : edges) {
            if (!dsu.unionfind(edge[0], edge[1])) return false;
        }
        return true;
    }
};