class DSU {
    vector<int> parent;
    int remaining;
public:
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        remaining = n;
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        parent[pb] = pa;
        remaining--;
        return true;
    }
    
    int getRemaining() {
        return remaining;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // sort(edges.begin(), edges.end(), [](vector<int>&e1, vector<int>&e2) {return e1[0]>e2[0];});
        
        DSU alice(n), bob(n);
        
        int ans = 0;
        for (int i = 3; i>=1;i--) {
            for (auto edge : edges) {
                if (edge[0] != i) continue;
                if (edge[0] == 1) {
                    if(!alice.unionfind(edge[1], edge[2])) ans++;
                } else if (edge[0] == 2) {
                    if(!bob.unionfind(edge[1], edge[2])) ans++;
                } else {
                    if ((!alice.unionfind(edge[1], edge[2])) || (!bob.unionfind(edge[1], edge[2]))) ans++;
                }
            }
        }
        
        if (alice.getRemaining() != 1 || bob.getRemaining() != 1) return -1;
        return ans;
    }
};