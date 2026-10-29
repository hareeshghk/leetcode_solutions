class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int ansleft=-1, ansright=-1;

        int ans = 0;
        // O(N^2) time, O(1) space
        for (int i = 0; i < n; ++i) {
            // s[i] being centre of polindrome
            int left = i-1, right = i+1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right-left-1 > ans) {
                ansleft = left+1;
                ansright = right-1;
                ans = right-left-1;
            }

            // S[i] being one of centre of polindrome only if s[i] == s[i+1]

            if (i!=n-1 && s[i] == s[i+1]) {
                left = i-1;
                right = i+2;

                while (left >= 0 && right < n && s[left] == s[right]) {
                    left--;
                    right++;
                }

                if (right-left-1 > ans) {
                    ansleft = left+1;
                    ansright = right-1;
                    ans = right-left-1;
                }
            }
        }

        return s.substr(ansleft, ans);
    }
};