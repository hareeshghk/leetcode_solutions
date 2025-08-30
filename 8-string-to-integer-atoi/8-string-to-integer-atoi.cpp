#include <string>

class Solution {
public:
    int myAtoi(string s) {
        int start = s.find_first_not_of(' ', 0);
        
        if (start == string::npos) return 0;
        
        bool is_neg = false;
        if (s[start] == '-') {
            is_neg = true;
            start++;
        } else if (s[start] == '+') {
            start++;
        }
        
        long long int result = 0;
        while (start < s.length()) {
            int digit = s[start]-'0';
            if (digit < 0 || digit > 9) break;
            if (is_neg) {
                result = result*10 - digit;
                if (result < INT_MIN) {
                    result = INT_MIN;
                    break;
                }
            } else {
                result = result*10 + digit;
                if (result > INT_MAX) {
                    result = INT_MAX;
                    break;
                }
            }
            ++start;
        }
        
        return result;
    }
};
