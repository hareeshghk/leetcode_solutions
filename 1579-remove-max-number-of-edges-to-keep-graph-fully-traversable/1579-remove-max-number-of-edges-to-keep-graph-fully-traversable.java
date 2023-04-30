class DSU {
    int n, count;
    int[] parent;
    
    public DSU(int num) {
        n = num+1;
        count = num;
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
        count--;
        parent[pb] = pa;
        return true;
    }
    
    public boolean allCovered() {
        return (count==1);
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        DSU dsu1 = new DSU(n);
        DSU dsu2 = new DSU(n);
        
        int answer = 0;
        for (int[] edge : edges) {
            if (edge[0] == 3) {
                if (!dsu1.unionfind(edge[1], edge[2])) {
                    answer++;
                }
                
                dsu2.unionfind(edge[1], edge[2]);
            }
        }
        
        
        for (int[] edge : edges) {
            if (edge[0] == 1) {
                if (!dsu1.unionfind(edge[1], edge[2])) {
                    answer++;
                }
            } else if(edge[0] == 2) {
                if (!dsu2.unionfind(edge[1], edge[2])) {
                    answer++;
                }
            }
        }
        
        return (dsu1.allCovered() && dsu2.allCovered())?answer:-1;
    }
}