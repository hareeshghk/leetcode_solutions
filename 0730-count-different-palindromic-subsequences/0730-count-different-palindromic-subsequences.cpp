class Solution {
    int MOD = 1000000007;
    vector<vector<vector<int>>> dp;
    string s;
public:
    int countPalindromicSubsequences(string str) {
        s = str;
        int n = s.length();

        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(4, -1)));

        int answer = 0;

        for (int i = 0; i < 4; ++i) {
            answer = (answer + findPolindromesSquences(0, n-1, i))%MOD;
        }
        return answer;
    }
private:
    int findPolindromesSquences(int left, int right, int enclosingChar) {
        if (left > right) return 0;

        if (left == right) {
            if (s[left] != ('a'+enclosingChar)) return 0;
            return 1;
        }

        if (dp[left][right][enclosingChar] != -1) return dp[left][right][enclosingChar];

        int currentCount  = 0;
        if (s[left] == s[right] && s[left] == ('a'+enclosingChar)) {
            currentCount = 2;
            for (int i = 0; i < 4; ++i) {
                currentCount = (currentCount + findPolindromesSquences(left+1, right-1, i)) % MOD;
            }
        } else {
            currentCount = (currentCount + findPolindromesSquences(left+1, right, enclosingChar)) %MOD;
            currentCount = (currentCount + findPolindromesSquences(left, right-1, enclosingChar)) %MOD;
            currentCount = (MOD + currentCount - findPolindromesSquences(left+1, right-1, enclosingChar)) %MOD;
        }
        return dp[left][right][enclosingChar] = currentCount;
    }
};