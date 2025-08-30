#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return numdecodings(s, 0);
    }
    vector<int> dp;
    int numdecodings(string &s, int idx) {
        if (idx == s.length()) return 1;
        
        if (dp[idx] != -1) return dp[idx];
        
        int n1 = 0;
        if (s[idx] != '0') {
            n1 = numdecodings(s, idx+1);
        }

        int n2 = 0;
        if (idx+1 != s.length() && isvalid(s[idx], s[idx+1])) {
            n2 = numdecodings(s, idx+2);
        }
        return dp[idx] = n1+n2;
    }
    
    bool isvalid(char a, char b) {
        if (a == '0') return false;
        int x = a-'0';
        x = x*10 + (b-'0');
        
        return (x>=1 && x <=26);
    }
};
