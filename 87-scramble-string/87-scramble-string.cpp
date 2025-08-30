#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1, s2, 0, s1.length()-1, 0, s2.length()-1);
    }
    
    unordered_map<string, bool> dp;
    bool isScramble(string &s1, string &s2, int l1, int e1, int l2, int e2) {
        if (l1 == e1) {
            return (s1[l1] == s2[l2]);
        }
        string matcher = to_string(l1)+","+to_string(l2)+","+to_string(e1-l1+1);
        if (dp.find(matcher) != dp.end()) return dp[matcher];
        int n = e1 - l1 + 1;
        bool val = false;
        for (int i = 1; i < n; i++) {
            val = val || (isScramble(s1, s2, l1, l1+i-1, l2, l2+i-1) && isScramble(s1, s2, l1+i, e1, l2+i, e2));
            val = val || (isScramble(s1, s2, l1, l1+i-1, e2-i+1, e2) && isScramble(s1, s2, l1+i, e1, l2, e2-i));
        }
        dp[matcher] = val;
        return val;
    }
};
