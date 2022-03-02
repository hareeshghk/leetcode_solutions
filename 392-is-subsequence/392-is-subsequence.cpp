class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m > n) return false;
        int i = 0, j=0;
        
        while (i < n && j < m) {
            if (s[j]==t[i]) {
                j++;
            }
            i++;
        }
        
        return (j==m);
    }
};