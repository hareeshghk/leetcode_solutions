class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack, t_stack;
        
        for (auto ch : s) {
            if (ch != '#') {
                s_stack.push(ch);
            } else if(!s_stack.empty()) {
                s_stack.pop();
            }
        }
        
        for (auto ch : t) {
            if (ch != '#') {
                t_stack.push(ch);
            } else if(!t_stack.empty()) {
                t_stack.pop();
            }
        }
        
        if (s_stack.size() != t_stack.size()) return false;
        
        while (!s_stack.empty()) {
            if (s_stack.top() != t_stack.top()) {
                return false;
            }
            s_stack.pop();
            t_stack.pop();
        }
        
        return true;
    }
};