class DSU {
    int[] parent;
    public DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    public int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    
    public boolean unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) {
            return false;
        }
        
        parent[pb] = pa;
        return true;
    }
}

class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        DSU dsu = new DSU(n);
        int provinces = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    if (dsu.unionfind(i, j)) {
                        --provinces;
                    }
                }
            }
        }
        
        return provinces;
    }
}