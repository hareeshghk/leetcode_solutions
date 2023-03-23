class DSA {
    int n, disconnected, extraThreads;
    int[] parents;
    
    public DSA(int num) {
        n = num;
        disconnected = num;
        parents = new int[n];
        extraThreads = 0;
        
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }
    
    public int find(int a) {
        if (parents[a] != a) {
            parents[a] = find(parents[a]);
        }
        return parents[a];
    }
    
    public void unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) {
            extraThreads++;
        } else {
            --disconnected;
            parents[pb] = pa;
        }
    }
    
    public int getDisConnected() {
        return disconnected;
    }
    
    public int GetExtraThreads() {
        return extraThreads;
    }
}

class Solution {
    public int makeConnected(int n, int[][] connections) {
        DSA dsa = new DSA(n);
        
        for (int[] connection : connections) {
            dsa.unionfind(connection[0], connection[1]);
        }
        
        return (dsa.getDisConnected()-1 <= dsa.GetExtraThreads())? dsa.getDisConnected()-1:-1;
    }
}