#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seen_digit = false;
        bool seen_dot = false;
        bool seen_exponent = false;
        
        int idx = 0;
        
        while (idx < s.length()) {
            if (isdigit(s[idx])) {
                seen_digit = true;
            } else if (s[idx] == '.') {
                if (seen_dot) return false;
                if (seen_exponent) return false;
                seen_dot = true;
            } else if (s[idx] == 'e' || s[idx] == 'E') {
                if (!seen_digit) return false;
                if (seen_exponent) return false;
                
                seen_exponent = true;
                seen_digit = false;
            } else if (s[idx] == '+'||s[idx] =='-') {
                if (idx != 0 && ((s[idx-1] != 'e')&&(s[idx-1] != 'E'))) return false;
            } else {
                return false;
            }
            ++idx;
        }
        return seen_digit;
    }
};
