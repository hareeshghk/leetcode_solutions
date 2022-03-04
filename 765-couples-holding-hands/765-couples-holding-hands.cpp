class Solution {
public:
    vector<int> parent;
    int num_dj_comp;
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        parent.resize(n);
        num_dj_comp =n;
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            // a, b are people sitting on ith couch.
            // for male or female their num/2 gives a single num because
            // they are even and even+1 type. like 0,1 and 2,3;
            // if both are equal then we can say they are in correct position.
            int a = row[2*i];
            int b = row[2*i+1];
            if(unionf(a/2, b/2)) {
                num_dj_comp--;
            }
        }
        return n - num_dj_comp;
    }
    
    bool unionf(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) return false;
        
        parent[pa] = pb;
        return true;
    }
    
    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
};