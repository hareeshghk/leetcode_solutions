class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        
        k -= n;
        
        for (int i = n-1; i >=0 && k > 0; i--) {
            int diff = min(k,25);
            ans[i] = (char)(ans[i]+diff);
            k-=diff;
        }
        return ans;
    }
};