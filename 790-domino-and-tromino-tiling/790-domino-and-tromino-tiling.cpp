class Solution {
public:
    int numTilings(int n) {
        if (n<=2) return n;
        vector<int> fc(n+1, 0);
        vector<int> pc(n+1, 0);
        
        fc[1] = 1;
        fc[2] = 2;
        pc[2] = 1;
        int mod = 1000000007;
        for (int i = 3; i<=n;i++) {
            fc[i] = ((fc[i-1]%mod) + ((fc[i-2]%mod) + (2*pc[i-1])%mod)%mod)%mod;
            pc[i] = (pc[i-1]+fc[i-2])%mod;
        }
        return fc[n];
    }
};