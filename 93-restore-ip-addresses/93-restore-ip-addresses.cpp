#include <string>
#include <vector>

class Solution {
public:
    vector<string> ans;
    vector<string> candidates;
    int s_len;
    vector<string> restoreIpAddresses(string s) {
        s_len = s.length();
        evaluateIpAddress(s, 3, 0);
        return ans;
    }
    
    void evaluateIpAddress(string &s, int dots, int curidx) {
        if (curidx >= s_len) return;

        if ((s_len - curidx) > 3*(dots+1)) return;
        
        if (dots == 0) {
            if (validsegment(s, curidx, s_len-1)) {
                string curstr = "";
                for (auto candidate : candidates) {
                    curstr += candidate;
                    curstr += ".";
                }
                curstr += s.substr(curidx, s_len-curidx);
                ans.push_back(curstr);
            }
            return;
        }
        
        for (int i = curidx; i<= curidx+2 && i < s_len; ++i) {
            if (validsegment(s, curidx, i)) {
                candidates.push_back(s.substr(curidx, i-curidx+1));
                evaluateIpAddress(s, dots-1, i+1);
                candidates.pop_back();
            }
        }
    }
    
    bool validsegment(string &s, int start, int end) {
        int n = end-start+1;
        if (n > 3 || n == 0) return false;
        
        int val = stoi(s.substr(start, n));
        
        if (s[start] == '0' && n != 1) return false;
        
        return (val<=255);
    }
    
};
