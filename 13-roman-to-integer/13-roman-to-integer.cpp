class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {{'M', 1000},{'D', 500},{'C', 100},{'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        
        int n = s.length();
        int ans = 0;
        
        if (n==0) return ans;
        
        for (int i = 0; i < n-1; ++i) {
            if (values[s[i]] >= values[s[i+1]]) {
                ans += values[s[i]];
            } else {
                ans -= values[s[i]];
            }
        }
        
        ans += values[s[n-1]];
        return ans;
    }
};