class DSU {
    int[] parent;
    int n;
    public DSU(int nums) {
        n = nums;
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
        
        if (pa == pb) return false;
        
        parent[pb] = pa;
        return true;
    }
}

class Solution {
    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        
        DSU dsu = new DSU(n);
        
        int answer = n;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (matched(strs, i, j)) {
                    if(dsu.unionfind(i, j)) {
                        answer--;
                    }
                }
            }
        }
        
        return answer;
    }
    
    private boolean matched(String[] strs, int i, int j) {
        String str1 = strs[i];
        String str2 = strs[j];
        
        int unmatch = 0;
        for (int k = 0; k < str1.length(); ++k) {
            if (str1.charAt(k) != str2.charAt(k)) {
                unmatch++;
                if(unmatch > 2) break;
            }
        }
        
        return (unmatch==0||unmatch==2);
    }
}