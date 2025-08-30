#include <string>
#include <vector>

class Solution {
public:
    int n;
    bool checkValidString(string s) {
        n = s.length();
        dp.resize(n, vector<int>(n+1, -1));
        return isValid(0, 0, s);
    }
    
    vector<vector<int>> dp;
    bool isValid(int idx, int open_left, const string &s) {
        if (idx == n) {
            return (open_left == 0);
        }
        
        if (dp[idx][open_left] != -1) {
            return dp[idx][open_left]==0?false:true;
        }
        
        bool result;
        if (s[idx] == '(') {
            result = isValid(idx+1, open_left+1, s);
        } else if (s[idx] ==')') {
            if (open_left <= 0) result = false;
            else result = isValid(idx+1, open_left-1, s);
        } else {
            if (open_left <= 0) {
                result = isValid(idx+1, open_left+1, s) || isValid(idx+1, open_left, s);
            } else {
                result = isValid(idx+1, open_left+1, s) || isValid(idx+1, open_left, s) || isValid(idx+1, open_left-1, s);
            }
        }
        
        dp[idx][open_left] = result?1:0;
        return result;
    }
};
