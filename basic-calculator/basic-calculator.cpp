#include <string>
using namespace std;

class Solution {
public:
    int idx;
    int calculate(string s) {
        idx = 0;
        int n = s.length();
        
        int prev = getVal(s);
        
        while (idx < n) {
            char op = getOp(s);
            int current = getVal(s);
            prev = Perform(op, prev, current);
        }
        return prev;
    }
    
    int Perform(char op, int a, int b) {
        if (op == '+') {
            return a+b;
        } else {
            return a-b;
        }
    }
    
    int calculateBraces(string &s) {
        int prev = getVal(s);
        
        while (s[idx] != ')') {
            char op = getOp(s);
            int current = getVal(s);
            prev = Perform(op, prev, current);
        }
        idx++;
        return prev;
    }
    
    int getVal(string &s) {
        while (idx < s.length() && s[idx] == ' ') idx++;
        bool negative = false;
        if (s[idx] == '-') {
            negative = true;
            idx++;
        }
        
        while (idx < s.length() && s[idx] == ' ') idx++;
        
        int val;
        if (s[idx] == '(') {
            idx++;
            val = calculateBraces(s);
            while (idx < s.length() && s[idx] == ' ') ++idx;
        } else {
            int j = idx;
            while (idx < s.length() && ((s[idx] - '0') >=0 && (s[idx] - '0') <= 9)) idx++;
            val = stoi(s.substr(j, idx-j));
            while (idx < s.length() && s[idx] == ' ') ++idx;
        }
        return negative?-val:val;
    }
    
    char getOp(string &s) {
        while (s[idx] == ' ') idx++;
        char op = s[idx++];
        while (idx < s.length() && s[idx] == ' ') ++idx;
        return op;
    }
};
