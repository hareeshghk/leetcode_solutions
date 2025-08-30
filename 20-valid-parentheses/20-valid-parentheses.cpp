#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> s_stack;
        for (auto ch : s) {
            if (ch == '[' || ch == '(' || ch == '{') {
                s_stack.push(ch);
                continue;
            }
            
            if (s_stack.empty()) return false;
            
            char top_char = s_stack.top();
            
            if ((ch == ')' && top_char != '(') ||
                (ch == ']' && top_char != '[') ||
                (ch == '}' && top_char != '{') ) {
                return false;
            }
            
            s_stack.pop();
        }
        
        return s_stack.empty();
    }
};
