#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        dp.clear();
        if (s == p) return true;
        
        if (s_len == 0 || p_len == 0) return false;
        
        if (p[0]=='*') {
            cout << "Invalid String";
            return false;
        }
        
        return isMatch(s, p, 0, 0);
    }
    
    bool isMatch(const string &s,const string &p,int sidx, int pidx) {
        string matcher = to_string(sidx)+","+to_string(pidx);
        if (dp.find(matcher) != dp.end()) return dp[matcher];
        if (sidx >= s.length() || pidx >= p.length()) {
            if(sidx >= s.length() && pidx >= p.length()) return true;
            else if (sidx >= s.length()) {
                if (pidx+1 < p.length() && p[pidx+1] == '*') {
                    dp[matcher] = isMatch(s,p,sidx, pidx+2);
                    return dp[matcher];
                }
                return false;
            }
            else return false;
        }
        
        bool val = false;
        if (pidx+1 < p.length() && p[pidx+1] == '*') {
            if (p[pidx] == '.' || s[sidx] == p[pidx]) {
                val = (isMatch(s,p,sidx+1, pidx+2) || (isMatch(s,p,sidx, pidx+2)||isMatch(s,p,sidx+1, pidx)));
            } else {
                val = isMatch(s, p, sidx, pidx+2);
            }
        } else {
            if (p[pidx] == '.' || s[sidx] == p[pidx]) {
                val = isMatch(s, p, sidx+1, pidx+1);
            }
        }
        dp[matcher] = val;
        return val;
    }
};
