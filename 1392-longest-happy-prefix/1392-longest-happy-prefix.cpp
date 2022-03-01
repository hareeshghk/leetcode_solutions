class Solution {
public:
    string longestPrefix(string s) {
        // do kmp which is O(n) and return max len prefix.
        // kmp gives proper suffix.
        int n = s.length();
        
        vector<int> kmp(n, 0);
        
        int len = 0;
        
        int max_len = 0;
        kmp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[len]) {
                len++;
                kmp[i] = len;
            } else {
                if (len == 0) continue;
                len = kmp[len-1];
                i--;
            }
        }
        
        return s.substr(0, kmp[n-1]);
    }
};