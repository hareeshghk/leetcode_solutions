#include <algorithm>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU(int capacity) {
        parent.resize(capacity + 1);
        for (int i = 0; i <= capacity; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
        
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
            
        parent[pb] = pa;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU d(n);
        for (auto edge : edges) {
            if(!d.unionfind(edge[0], edge[1])) return edge;
        }
        return edges[0];
    }
};
