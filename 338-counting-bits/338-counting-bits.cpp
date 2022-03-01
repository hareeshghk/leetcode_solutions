class Solution {
public:
    vector<int> countBits(int n) {
        if (n==0) return {0};
        if (n==1) return {0,1};
        
        vector<int> ans(n+1, 0);
        
        
        for(int i = 1; i<=n; i++) {
            ans[i] = ans[i>>1]+(i&1);
        }

        return ans;
    }
};