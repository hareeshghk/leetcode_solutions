class Solution {
public:
    int numWays(int n, int k) {
        if (k == 1) {
            if (n<=2) return 1;
            else return 0;
        }
        
        if (n==1) return k;
        
        int v1 = k;
        int v2 = 1;
        int temp;
        for (int i = 2; i < n; i++) {
            temp = v1;
            v1 = (v1+v2)*(k-1);
            v2 = temp;
        }
        
        return k*v1;
    }
};