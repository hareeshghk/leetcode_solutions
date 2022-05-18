class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return longest(s, 0, n-1);
    }
    
    vector<vector<int>> dp;
    int longest(string &s, int left, int right) {
        if (left > right) return 0;
        if (left == right) return 1;
        
        if (dp[left][right] != -1) return dp[left][right];
        int result = INT_MIN;
        
        if (s[left] == s[right]) {
            result = 2 + longest(s, left+1, right-1);
        } else {
            result = max(longest(s, left+1, right), longest(s, left, right-1));
        }
        dp[left][right]=result;
        return result;
    }
};