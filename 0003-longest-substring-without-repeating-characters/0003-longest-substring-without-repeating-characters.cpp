class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> position;
        int n = s.length();

        int ws = 0;
        int ans = 0;

        for (int we = 0; we < n; ++we) {
            if (position.find(s[we]) != position.end()) {
                ws = max(ws, position[s[we]]+1);
            }

            ans = max(ans, we-ws+1);
            position[s[we]] = we;
        }

        return ans;
    }
};