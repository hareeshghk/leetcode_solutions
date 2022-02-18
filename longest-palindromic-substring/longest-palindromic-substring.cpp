class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;string maxString = "";
        maxString += s[0];
        int leftwall = 0, rightwall = s.length()-1;
        for (int i = 1; i < s.length(); ++i) {
            int j = 1;
            int curlen = 1, left = i-1, right = i+1;
            while (left >= leftwall && right <= rightwall && s[left] == s[right]) {
                curlen += 2;
                --left; ++right;
            }
            
            if (curlen > maxLen) {
                maxLen = curlen;
                maxString = s.substr(left + 1, curlen);
            }
            
            curlen = 0;
            left = i - 1;
            right = i;
            if (s[left] != s[right]) continue;
            
            while (left >= leftwall && right <= rightwall && s[left] == s[right]) {
                curlen += 2;
                --left; ++right;
            }
            
            if(curlen > maxLen) {
                maxLen = curlen;
                maxString = s.substr(left + 1, curlen);
            }
        }
        return maxString;
    }
};