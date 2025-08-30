#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return findnummincuts(s, 0, n-1);
    }
    
    bool ispolindrome(const string &s, int l, int r) {
        if (dp[l][r] ==0) return true;
        int a=l, b=r;
        while (l<r) {
            if (s[l]!=s[r]) return false;
            l++;r--;
        }
        
        while (a<=b) {
            dp[a][b]=0;
            a++;b--;
        }
        return true;
    }
    vector<vector<int>> dp;
    int findnummincuts(const string &s, int start, int end) {
        if (start == end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        if (ispolindrome(s, start, end)) {
            dp[start][end] = 0;
            return 0;
        }
        
        int result = INT_MAX;
        for (int i = start; i <= end; i++) {
            if (ispolindrome(s, start, i)) {
                result = min(result, 1 + findnummincuts(s, i+1, end));
            }
        }
        dp[start][end] = result;
        return result;
    }
};
