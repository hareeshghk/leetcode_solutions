class DSA {
    int n;
    int[] parent, count;
    
    public DSA(int num) {
        n = num;
        
        parent = new int[n];
        count = new int[n];
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            count[i] = 1;
        }
    }
    
    public int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    
    public void unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        
        if (pa != pb) {
            parent[pb] = pa;
            count[pa] += count[pb];
        }
    }
    
    public ArrayList<Integer> getCounts() {
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                answer.add(count[i]);
            }
        }
        return answer;
    }
}

class Solution {
    public long countPairs(int n, int[][] edges) {
        DSA dsa = new DSA(n);
        
        for (int[] edge : edges) {
            dsa.unionfind(edge[0], edge[1]);
        }
        
        ArrayList<Integer> counts = dsa.getCounts();
        
        ArrayList<Long> prefixSum = new ArrayList<Long>();
        
        long cummulativeCount = 0;
        prefixSum.add(cummulativeCount);
            
        for (Integer count : counts) {
            cummulativeCount += count;
            prefixSum.add(cummulativeCount);
        }
        
        long answer = 0;
        
        for (int i = counts.size()-1; i>=0; --i) {
            answer += counts.get(i)*prefixSum.get(i);
        }
        
        return answer;
    }
}