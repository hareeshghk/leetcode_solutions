class DSA {
    int n, disconnected;
    int[] parents, extraThreads;
    
    public DSA(int num) {
        n = num;
        disconnected = num;
        parents = new int[n];
        extraThreads = new int[n];
        
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            extraThreads[i] = 0;
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
            extraThreads[pa]++;
        } else {
            --disconnected;
            parents[pb] = pa;
            extraThreads[pa] += extraThreads[pb];
        }
    }
    
    public int getDisConnected() {
        return disconnected;
    }
    
    public int GetExtraThreads() {
        int val = 0;
        
        for (int i = 0; i < n; ++i) {
            if (parents[i] == i) {
                val += extraThreads[i];
            }
        }
        
        return val;
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