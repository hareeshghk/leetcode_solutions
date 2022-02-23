class Solution {
public:
    string s, t;
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        this->s = s;
        this->t = t;
        
        if(abs(m-n) > 1) return false;
        
        return recurse(0, 0, false, m, n);
    }
    
    unordered_map<string, bool> dp;
    bool recurse(int i, int j, bool used, int m, int n) {
        if (i == m && j == n) {
            if (used) return true;
            return false;
        }
        
        if (i == m) {
            if (j == n-1 && !used) return true;
            return false;
        }
        
        if (j == n) {
            if(i==m-1 && !used) return true;
            return false;
        }
        
        string matcher = to_string(i)+","+to_string(j)+","+to_string(used);
        
        if (dp.find(matcher) != dp.end()) return dp[matcher];
        bool result;
        if (s[i] == t[j]) {
            result = recurse(i+1, j+1, used, m, n);
        } else {
            if (used) result = false;
            else result = recurse(i+1, j, true, m, n)||(recurse(i, j+1, true, m, n)||recurse(i+1, j+1, true, m, n));
        }
        
        dp[matcher] = result;
        
        return result;
    }
};