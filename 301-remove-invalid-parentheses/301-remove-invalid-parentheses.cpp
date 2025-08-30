#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_set<string> seen;
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        
        int misplacedOpen = 0;
        int misplacedClose = 0;
        
        int opened=0,closed = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') opened++;
            else if (s[i] ==')') closed++;
            if (closed > opened) {
                misplacedClose++;
                closed = opened;
            }
        }
        misplacedOpen = opened-closed;
        
        // cout << misplacedOpen << " " << misplacedClose << endl;
        string cur = "";
        backtrack(s, 0, misplacedOpen, misplacedClose, 0, 0, cur);
        return result;
    }
    
    void backtrack(string &s, int idx, int mo, int mc, int o, int c, string &cur) {
        if (o < c) return;
        
        if (idx == s.length()) {
            if (mo == 0 && mc == 0) {
                if (seen.count(cur) == 0) {
                    seen.insert(cur);
                    result.push_back(cur);
                }
            }
            return;
        }
        
        if ((s[idx] == '(' && mo > 0)||(s[idx] ==')' && mc >0)) {
            backtrack(s, idx+1, mo - (s[idx]=='('?1:0), mc - (s[idx]==')'?1:0), o, c, cur);
        }
        
        cur += s[idx];
            
        if (s[idx] == '(') {
            backtrack(s, idx+1, mo, mc, o+1, c, cur);
        } else if (s[idx] == ')') {
            backtrack(s, idx+1, mo, mc, o, c+1, cur);
        } else {
            backtrack(s, idx+1, mo, mc, o, c, cur);
        }
        cur.pop_back();
    }
    
    bool IsValid(string &s, int idx, int o, int c) {
        while (idx < s.length()) {
            if (s[idx] == '(') {
                o++;
            } else if (s[idx] == ')') {
                c++;
            }
            if (o < c) return false;
            idx++;
        }
        return true;
    }
};
