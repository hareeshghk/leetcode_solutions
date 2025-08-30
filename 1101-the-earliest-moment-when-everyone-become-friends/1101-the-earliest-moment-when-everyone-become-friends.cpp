#include <algorithm>
#include <vector>

class DSU {
    vector<int> parent;
    int remaining;
public:
    DSU(int n) {
        parent.resize(n);
        remaining = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int a) {
        if(parent[a] !=a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if(pa==pb) return false;
        parent[pb] = pa;
        --remaining;
        return true;
    }
    
    int getremaining() {
        return remaining;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](const vector<int>&a, const vector<int>&b){return a[0]<b[0];});
        
        DSU d(n);
        
        for (auto log : logs) {
            d.unionfind(log[1], log[2]);
            if (d.getremaining() == 1) return log[0];
        }
        return -1;
    }
};
